int marker_l_precomp;

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
void QDECL SourceError(source_t *source, char *str, ...)
{
  char text[1024];
  va_list ap;

  va_start(ap, str);
  vsprintf(text, str, ap);
  va_end(ap);
#ifdef BOTLIB
  botimport.Print(PRT_ERROR, "file %s, line %d: %s\n",
                  source->scriptstack->filename, source->scriptstack->line,
                  text);
#endif // BOTLIB
#ifdef MEQCC
  printf("error: file %s, line %d: %s\n", source->scriptstack->filename,
         source->scriptstack->line, text);
#endif // MEQCC
#ifdef BSPC
  Log_Print("error: file %s, line %d: %s\n", source->scriptstack->filename,
            source->scriptstack->line, text);
#endif // BSPC
} // end of the function SourceError

//===========================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//===========================================================================
void QDECL SourceWarning(source_t *source, char *str, ...)
{
  char text[1024];
  va_list ap;

  va_start(ap, str);
  vsprintf(text, str, ap);
  va_end(ap);
#ifdef BOTLIB
  botimport.Print(PRT_WARNING, "file %s, line %d: %s\n",
                  source->scriptstack->filename, source->scriptstack->line,
                  text);
#endif // BOTLIB
#ifdef MEQCC
  printf("warning: file %s, line %d: %s\n", source->scriptstack->filename,
         source->scriptstack->line, text);
#endif // MEQCC
#ifdef BSPC
  Log_Print("warning: file %s, line %d: %s\n", source->scriptstack->filename,
            source->scriptstack->line, text);
#endif // BSPC
} // end of the function SourceWarning

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_StringizeTokens(token_t *tokens, token_t *token)
{
  token_t *t;

  token->type = TT_STRING;
  token->whitespace_p = NULL;
  token->endwhitespace_p = NULL;
  token->string[0] = '\0';
  strcat(token->string, "\"");
    for (t = tokens; t; t = t->next) {
      strncat(token->string, t->string, MAX_TOKEN - strlen(token->string));
    } // end for
  strncat(token->string, "\"", MAX_TOKEN - strlen(token->string));
  return qtrue;
} // end of the function PC_StringizeTokens

int PC_OperatorPriority(int op)
{
    switch (op) {
    case P_MUL:
      return 15;
    case P_DIV:
      return 15;
    case P_MOD:
      return 15;
    case P_ADD:
      return 14;
    case P_SUB:
      return 14;

    case P_LOGIC_AND:
      return 7;
    case P_LOGIC_OR:
      return 6;
    case P_LOGIC_GEQ:
      return 12;
    case P_LOGIC_LEQ:
      return 12;
    case P_LOGIC_EQ:
      return 11;
    case P_LOGIC_UNEQ:
      return 11;

    case P_LOGIC_NOT:
      return 16;
    case P_LOGIC_GREATER:
      return 12;
    case P_LOGIC_LESS:
      return 12;

    case P_RSHIFT:
      return 13;
    case P_LSHIFT:
      return 13;

    case P_BIN_AND:
      return 10;
    case P_BIN_OR:
      return 8;
    case P_BIN_XOR:
      return 9;
    case P_BIN_NOT:
      return 16;

    case P_COLON:
      return 5;
    case P_QUESTIONMARK:
      return 5;
    } // end switch
  return qfalse;
} // end of the function PC_OperatorPriority

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_line(source_t *source)
{
  SourceError(source, "#line directive not supported");
  return qfalse;
} // end of the function PC_Directive_line

//============================================================================
//
// Parameter:			-
// Returns:				-
// Changes Globals:		-
//============================================================================
int PC_SourceFileAndLine(int handle, char *filename, int *line)
{
  if (handle < 1 || handle >= MAX_SOURCEFILES)
    return qfalse;
  if (!sourceFiles[handle])
    return qfalse;

  strcpy(filename, sourceFiles[handle]->filename);
  if (sourceFiles[handle]->scriptstack)
    *line = sourceFiles[handle]->scriptstack->line;
  else
    *line = 0;
  return qtrue;
} // end of the function PC_SourceFileAndLine

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_ReadSourceToken(source_t *source, token_t *token)
{
  token_t *t;
  script_t *script;
  int type, skip;

    // if there's no token already available
    while (!source->tokens) {
      // if there's a token to read from the script
      if (PS_ReadToken(source->scriptstack, token))
        return qtrue;
        // if at the end of the script
        if (EndOfScript(source->scriptstack)) {
            // remove all indents of the script
            while (source->indentstack &&
                   source->indentstack->script == source->scriptstack) {
              SourceWarning(source, "missing #endif");
              PC_PopIndent(source, &type, &skip);
            } // end if
        }     // end if
      // if this was the initial script
      if (!source->scriptstack->next)
        return qfalse;
      // remove the script and return to the last one
      script = source->scriptstack;
      source->scriptstack = source->scriptstack->next;
      FreeScript(script);
    } // end while
  // copy the already available token
  Com_Memcpy(token, source->tokens, sizeof(token_t));
  // free the read token
  t = source->tokens;
  source->tokens = source->tokens->next;
  PC_FreeToken(t);
  return qtrue;
} // end of the function PC_ReadSourceToken

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_error(source_t *source)
{
  token_t token;

  strcpy(token.string, "");
  PC_ReadSourceToken(source, &token);
  SourceError(source, "#error directive: %s", token.string);
  return qfalse;
} // end of the function PC_Directive_error

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_else(source_t *source)
{
  int type, skip;

  PC_PopIndent(source, &type, &skip);
    if (!type) {
      SourceError(source, "misplaced #else");
      return qfalse;
    } // end if
    if (type == INDENT_ELSE) {
      SourceError(source, "#else after #else");
      return qfalse;
    } // end if
  PC_PushIndent(source, INDENT_ELSE, !skip);
  return qtrue;
} // end of the function PC_Directive_else

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_endif(source_t *source)
{
  int type, skip;

  PC_PopIndent(source, &type, &skip);
    if (!type) {
      SourceError(source, "misplaced #endif");
      return qfalse;
    } // end if
  return qtrue;
} // end of the function PC_Directive_endif

int PC_EvaluateTokens(source_t *source, token_t *tokens,
                      signed long int *intvalue, double *floatvalue,
                      int integer)
{
  operator_t *o, *firstoperator, *lastoperator;
  value_t *v, *firstvalue, *lastvalue, *v1, *v2;
  token_t *t;
  int brace = 0;
  int parentheses = 0;
  int error = 0;
  int lastwasvalue = 0;
  int negativevalue = 0;
  int questmarkintvalue = 0;
  double questmarkfloatvalue = 0;
  int gotquestmarkvalue = qfalse;
  int lastoperatortype = 0;
  //
  operator_t operator_heap[MAX_OPERATORS];
  int numoperators = 0;
  value_t value_heap[MAX_VALUES];
  int numvalues = 0;

  firstoperator = lastoperator = NULL;
  firstvalue = lastvalue = NULL;
  if (intvalue)
    *intvalue = 0;
  if (floatvalue)
    *floatvalue = 0;
    for (t = tokens; t; t = t->next) {
        switch (t->type) {
        case TT_NAME:
          {
              if (lastwasvalue || negativevalue) {
                SourceError(source, "syntax error in #if/#elif");
                error = 1;
                break;
              } // end if
              if (strcmp(t->string, "defined")) {
                SourceError(source, "undefined name %s in #if/#elif",
                            t->string);
                error = 1;
                break;
              } // end if
            t = t->next;
              if (!strcmp(t->string, "(")) {
                brace = qtrue;
                t = t->next;
              } // end if
              if (!t || t->type != TT_NAME) {
                SourceError(source, "defined without name in #if/#elif");
                error = 1;
                break;
              } // end if
            // v = (value_t *) GetClearedMemory(sizeof(value_t));
            AllocValue(v);
#if DEFINEHASHING
              if (PC_FindHashedDefine(source->definehash, t->string))
#else
              if (PC_FindDefine(source->defines, t->string))
#endif // DEFINEHASHING
              {
                v->intvalue = 1;
                v->floatvalue = 1;
              } // end if
              else {
                v->intvalue = 0;
                v->floatvalue = 0;
              } // end else
            v->parentheses = parentheses;
            v->next = NULL;
            v->prev = lastvalue;
            if (lastvalue)
              lastvalue->next = v;
            else
              firstvalue = v;
            lastvalue = v;
              if (brace) {
                t = t->next;
                  if (!t || strcmp(t->string, ")")) {
                    SourceError(source, "defined without ) in #if/#elif");
                    error = 1;
                    break;
                  } // end if
              }     // end if
            brace = qfalse;
            // defined() creates a value
            lastwasvalue = 1;
            break;
          } // end case
        case TT_NUMBER:
          {
              if (lastwasvalue) {
                SourceError(source, "syntax error in #if/#elif");
                error = 1;
                break;
              } // end if
            // v = (value_t *) GetClearedMemory(sizeof(value_t));
            AllocValue(v);
              if (negativevalue) {
                v->intvalue = -(signed int)t->intvalue;
                v->floatvalue = -t->floatvalue;
              } // end if
              else {
                v->intvalue = t->intvalue;
                v->floatvalue = t->floatvalue;
              } // end else
            v->parentheses = parentheses;
            v->next = NULL;
            v->prev = lastvalue;
            if (lastvalue)
              lastvalue->next = v;
            else
              firstvalue = v;
            lastvalue = v;
            // last token was a value
            lastwasvalue = 1;
            //
            negativevalue = 0;
            break;
          } // end case
        case TT_PUNCTUATION:
          {
              if (negativevalue) {
                SourceError(source, "misplaced minus sign in #if/#elif");
                error = 1;
                break;
              } // end if
              if (t->subtype == P_PARENTHESESOPEN) {
                parentheses++;
                break;
              } // end if
              else if (t->subtype == P_PARENTHESESCLOSE) {
                parentheses--;
                  if (parentheses < 0) {
                    SourceError(source, "too many ) in #if/#elsif");
                    error = 1;
                  } // end if
                break;
              } // end else if
              // check for invalid operators on floating point values
              if (!integer) {
                  if (t->subtype == P_BIN_NOT || t->subtype == P_MOD ||
                      t->subtype == P_RSHIFT || t->subtype == P_LSHIFT ||
                      t->subtype == P_BIN_AND || t->subtype == P_BIN_OR ||
                      t->subtype == P_BIN_XOR) {
                    SourceError(
                        source,
                        "illigal operator %s on floating point operands\n",
                        t->string);
                    error = 1;
                    break;
                  } // end if
              }     // end if
              switch (t->subtype) {
              case P_LOGIC_NOT:
              case P_BIN_NOT:
                {
                    if (lastwasvalue) {
                      SourceError(source, "! or ~ after value in #if/#elif");
                      error = 1;
                      break;
                    } // end if
                  break;
                } // end case
              case P_INC:
              case P_DEC:
                {
                  SourceError(source, "++ or -- used in #if/#elif");
                  break;
                } // end case
              case P_SUB:
                {
                    if (!lastwasvalue) {
                      negativevalue = 1;
                      break;
                    } // end if
                }     // end case

              case P_MUL:
              case P_DIV:
              case P_MOD:
              case P_ADD:

              case P_LOGIC_AND:
              case P_LOGIC_OR:
              case P_LOGIC_GEQ:
              case P_LOGIC_LEQ:
              case P_LOGIC_EQ:
              case P_LOGIC_UNEQ:

              case P_LOGIC_GREATER:
              case P_LOGIC_LESS:

              case P_RSHIFT:
              case P_LSHIFT:

              case P_BIN_AND:
              case P_BIN_OR:
              case P_BIN_XOR:

              case P_COLON:
              case P_QUESTIONMARK:
                {
                    if (!lastwasvalue) {
                      SourceError(source,
                                  "operator %s after operator in #if/#elif",
                                  t->string);
                      error = 1;
                      break;
                    } // end if
                  break;
                } // end case
              default:
                {
                  SourceError(source, "invalid operator %s in #if/#elif",
                              t->string);
                  error = 1;
                  break;
                } // end default
              }   // end switch
              if (!error && !negativevalue) {
                // o = (operator_t *) GetClearedMemory(sizeof(operator_t));
                AllocOperator(o);
                o->operator= t->subtype;
                o->priority = PC_OperatorPriority(t->subtype);
                o->parentheses = parentheses;
                o->next = NULL;
                o->prev = lastoperator;
                if (lastoperator)
                  lastoperator->next = o;
                else
                  firstoperator = o;
                lastoperator = o;
                lastwasvalue = 0;
              } // end if
            break;
          } // end case
        default:
          {
            SourceError(source, "unknown %s in #if/#elif", t->string);
            error = 1;
            break;
          } // end default
        }   // end switch
      if (error)
        break;
    } // end for
    if (!error) {
        if (!lastwasvalue) {
          SourceError(source, "trailing operator in #if/#elif");
          error = 1;
        } // end if
        else if (parentheses) {
          SourceError(source, "too many ( in #if/#elif");
          error = 1;
        } // end else if
    }     // end if
  //
  gotquestmarkvalue = qfalse;
  questmarkintvalue = 0;
  questmarkfloatvalue = 0;
    // while there are operators
    while (!error && firstoperator) {
      v = firstvalue;
        for (o = firstoperator; o->next; o = o->next) {
          // if the current operator is nested deeper in parentheses
          // than the next operator
          if (o->parentheses > o->next->parentheses)
            break;
            // if the current and next operator are nested equally deep in
            // parentheses
            if (o->parentheses == o->next->parentheses) {
              // if the priority of the current operator is equal or higher
              // than the priority of the next operator
              if (o->priority >= o->next->priority)
                break;
            } // end if
          // if the arity of the operator isn't equal to 1
          if (o->operator!= P_LOGIC_NOT && o->operator!= P_BIN_NOT)
            v = v->next;
            // if there's no value or no next value
            if (!v) {
              SourceError(source, "mising values in #if/#elif");
              error = 1;
              break;
            } // end if
        }     // end for
      if (error)
        break;
      v1 = v;
      v2 = v->next;
#ifdef DEBUG_EVAL
        if (integer) {
          Log_Write("operator %s, value1 = %d",
                    PunctuationFromNum(source->scriptstack, o->operator),
                    v1->intvalue);
          if (v2)
            Log_Write("value2 = %d", v2->intvalue);
        } // end if
        else {
          Log_Write("operator %s, value1 = %f",
                    PunctuationFromNum(source->scriptstack, o->operator),
                    v1->floatvalue);
          if (v2)
            Log_Write("value2 = %f", v2->floatvalue);
        } // end else
#endif    // DEBUG_EVAL
        switch (o->operator) {
        case P_LOGIC_NOT:
          v1->intvalue = !v1->intvalue;
          v1->floatvalue = !v1->floatvalue;
          break;
        case P_BIN_NOT:
          v1->intvalue = ~v1->intvalue;
          break;
        case P_MUL:
          v1->intvalue *= v2->intvalue;
          v1->floatvalue *= v2->floatvalue;
          break;
        case P_DIV:
            if (!v2->intvalue || !v2->floatvalue) {
              SourceError(source, "divide by zero in #if/#elif\n");
              error = 1;
              break;
            }
          v1->intvalue /= v2->intvalue;
          v1->floatvalue /= v2->floatvalue;
          break;
        case P_MOD:
            if (!v2->intvalue) {
              SourceError(source, "divide by zero in #if/#elif\n");
              error = 1;
              break;
            }
          v1->intvalue %= v2->intvalue;
          break;
        case P_ADD:
          v1->intvalue += v2->intvalue;
          v1->floatvalue += v2->floatvalue;
          break;
        case P_SUB:
          v1->intvalue -= v2->intvalue;
          v1->floatvalue -= v2->floatvalue;
          break;
        case P_LOGIC_AND:
          v1->intvalue = v1->intvalue && v2->intvalue;
          v1->floatvalue = v1->floatvalue && v2->floatvalue;
          break;
        case P_LOGIC_OR:
          v1->intvalue = v1->intvalue || v2->intvalue;
          v1->floatvalue = v1->floatvalue || v2->floatvalue;
          break;
        case P_LOGIC_GEQ:
          v1->intvalue = v1->intvalue >= v2->intvalue;
          v1->floatvalue = v1->floatvalue >= v2->floatvalue;
          break;
        case P_LOGIC_LEQ:
          v1->intvalue = v1->intvalue <= v2->intvalue;
          v1->floatvalue = v1->floatvalue <= v2->floatvalue;
          break;
        case P_LOGIC_EQ:
          v1->intvalue = v1->intvalue == v2->intvalue;
          v1->floatvalue = v1->floatvalue == v2->floatvalue;
          break;
        case P_LOGIC_UNEQ:
          v1->intvalue = v1->intvalue != v2->intvalue;
          v1->floatvalue = v1->floatvalue != v2->floatvalue;
          break;
        case P_LOGIC_GREATER:
          v1->intvalue = v1->intvalue > v2->intvalue;
          v1->floatvalue = v1->floatvalue > v2->floatvalue;
          break;
        case P_LOGIC_LESS:
          v1->intvalue = v1->intvalue < v2->intvalue;
          v1->floatvalue = v1->floatvalue < v2->floatvalue;
          break;
        case P_RSHIFT:
          v1->intvalue >>= v2->intvalue;
          break;
        case P_LSHIFT:
          v1->intvalue <<= v2->intvalue;
          break;
        case P_BIN_AND:
          v1->intvalue &= v2->intvalue;
          break;
        case P_BIN_OR:
          v1->intvalue |= v2->intvalue;
          break;
        case P_BIN_XOR:
          v1->intvalue ^= v2->intvalue;
          break;
        case P_COLON:
          {
              if (!gotquestmarkvalue) {
                SourceError(source, ": without ? in #if/#elif");
                error = 1;
                break;
              } // end if
              if (integer) {
                if (!questmarkintvalue)
                  v1->intvalue = v2->intvalue;
              } // end if
              else {
                if (!questmarkfloatvalue)
                  v1->floatvalue = v2->floatvalue;
              } // end else
            gotquestmarkvalue = qfalse;
            break;
          } // end case
        case P_QUESTIONMARK:
          {
              if (gotquestmarkvalue) {
                SourceError(source, "? after ? in #if/#elif");
                error = 1;
                break;
              } // end if
            questmarkintvalue = v1->intvalue;
            questmarkfloatvalue = v1->floatvalue;
            gotquestmarkvalue = qtrue;
            break;
          } // end if
        }   // end switch
#ifdef DEBUG_EVAL
      if (integer)
        Log_Write("result value = %d", v1->intvalue);
      else
        Log_Write("result value = %f", v1->floatvalue);
#endif // DEBUG_EVAL
      if (error)
        break;
      lastoperatortype = o->operator;
        // if not an operator with arity 1
        if (o->operator!= P_LOGIC_NOT && o->operator!= P_BIN_NOT) {
          // remove the second value if not question mark operator
          if (o->operator!= P_QUESTIONMARK)
            v = v->next;
          //
          if (v->prev)
            v->prev->next = v->next;
          else
            firstvalue = v->next;
          if (v->next)
            v->next->prev = v->prev;
          else
            lastvalue = v->prev;
          // FreeMemory(v);
          FreeValue(v);
        } // end if
      // remove the operator
      if (o->prev)
        o->prev->next = o->next;
      else
        firstoperator = o->next;
      if (o->next)
        o->next->prev = o->prev;
      else
        lastoperator = o->prev;
      // FreeMemory(o);
      FreeOperator(o);
    } // end while
    if (firstvalue) {
      if (intvalue)
        *intvalue = firstvalue->intvalue;
      if (floatvalue)
        *floatvalue = firstvalue->floatvalue;
    } // end if
    for (o = firstoperator; o; o = lastoperator) {
      lastoperator = o->next;
      // FreeMemory(o);
      FreeOperator(o);
    } // end for
    for (v = firstvalue; v; v = lastvalue) {
      lastvalue = v->next;
      // FreeMemory(v);
      FreeValue(v);
    } // end for
  if (!error)
    return qtrue;
  if (intvalue)
    *intvalue = 0;
  if (floatvalue)
    *floatvalue = 0;
  return qfalse;
} // end of the function PC_EvaluateTokens

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
void FreeSource(source_t *source)
{
  script_t *script;
  token_t *token;
  define_t *define;
  indent_t *indent;
  int i;

    // PC_PrintDefineHashTable(source->definehash);
    // free all the scripts
    while (source->scriptstack) {
      script = source->scriptstack;
      source->scriptstack = source->scriptstack->next;
      FreeScript(script);
    } // end for
    // free all the tokens
    while (source->tokens) {
      token = source->tokens;
      source->tokens = source->tokens->next;
      PC_FreeToken(token);
    } // end for
#if DEFINEHASHING
    for (i = 0; i < DEFINEHASHSIZE; i++) {
        while (source->definehash[i]) {
          define = source->definehash[i];
          source->definehash[i] = source->definehash[i]->hashnext;
          PC_FreeDefine(define);
        } // end while
    }     // end for
#else     // DEFINEHASHING
          // free all defines
    while (source->defines) {
      define = source->defines;
      source->defines = source->defines->next;
      PC_FreeDefine(define);
    } // end for
#endif    // DEFINEHASHING
          // free all indents
    while (source->indentstack) {
      indent = source->indentstack;
      source->indentstack = source->indentstack->next;
      FreeMemory(indent);
    } // end for
#if DEFINEHASHING
  //
  if (source->definehash)
    FreeMemory(source->definehash);
#endif // DEFINEHASHING
       // free the source itself
  FreeMemory(source);
} // end of the function FreeSource

//============================================================================
//
// Parameter:			-
// Returns:				-
// Changes Globals:		-
//============================================================================
int PC_FreeSourceHandle(int handle)
{
  if (handle < 1 || handle >= MAX_SOURCEFILES)
    return qfalse;
  if (!sourceFiles[handle])
    return qfalse;

  FreeSource(sourceFiles[handle]);
  sourceFiles[handle] = NULL;
  return qtrue;
} // end of the function PC_FreeSourceHandle

int PC_ReadDollarDirective(source_t *source)
{
  token_t token;
  int i;

    // read the directive name
    if (!PC_ReadSourceToken(source, &token)) {
      SourceError(source, "found $ without name");
      return qfalse;
    } // end if
    // directive name must be on the same line
    if (token.linescrossed > 0) {
      PC_UnreadSourceToken(source, &token);
      SourceError(source, "found $ at end of line");
      return qfalse;
    } // end if
    // if if is a name
    if (token.type == TT_NAME) {
        // find the precompiler directive
        for (i = 0; dollardirectives[i].name; i++) {
            if (!strcmp(dollardirectives[i].name, token.string)) {
              return dollardirectives[i].func(source);
            } // end if
        }     // end for
    }         // end if
  PC_UnreadSourceToken(source, &token);
  SourceError(source, "unknown precompiler directive %s", token.string);
  return qfalse;
} // end of the function PC_ReadDirective

int PC_ReadDirective(source_t *source)
{
  token_t token;
  int i;

    // read the directive name
    if (!PC_ReadSourceToken(source, &token)) {
      SourceError(source, "found # without name");
      return qfalse;
    } // end if
    // directive name must be on the same line
    if (token.linescrossed > 0) {
      PC_UnreadSourceToken(source, &token);
      SourceError(source, "found # at end of line");
      return qfalse;
    } // end if
    // if if is a name
    if (token.type == TT_NAME) {
        // find the precompiler directive
        for (i = 0; directives[i].name; i++) {
            if (!strcmp(directives[i].name, token.string)) {
              return directives[i].func(source);
            } // end if
        }     // end for
    }         // end if
  SourceError(source, "unknown precompiler directive %s", token.string);
  return qfalse;
} // end of the function PC_ReadDirective

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_include(source_t *source)
{
  script_t *script;
  token_t token;
  char path[MAX_PATH];
#ifdef QUAKE
  foundfile_t file;
#endif // QUAKE

  if (source->skip > 0)
    return qtrue;
    //
    if (!PC_ReadSourceToken(source, &token)) {
      SourceError(source, "#include without file name");
      return qfalse;
    } // end if
    if (token.linescrossed > 0) {
      SourceError(source, "#include without file name");
      return qfalse;
    } // end if
    if (token.type == TT_STRING) {
      StripDoubleQuotes(token.string);
      PC_ConvertPath(token.string);
      script = LoadScriptFile(token.string);
        if (!script) {
          strcpy(path, source->includepath);
          strcat(path, token.string);
          script = LoadScriptFile(path);
        } // end if
    }     // end if
    else if (token.type == TT_PUNCTUATION && *token.string == '<') {
      strcpy(path, source->includepath);
        while (PC_ReadSourceToken(source, &token)) {
            if (token.linescrossed > 0) {
              PC_UnreadSourceToken(source, &token);
              break;
            } // end if
          if (token.type == TT_PUNCTUATION && *token.string == '>')
            break;
          strncat(path, token.string, MAX_PATH);
        } // end while
        if (*token.string != '>') {
          SourceWarning(source, "#include missing trailing >");
        } // end if
        if (!strlen(path)) {
          SourceError(source, "#include without file name between < >");
          return qfalse;
        } // end if
      PC_ConvertPath(path);
      script = LoadScriptFile(path);
    } // end if
    else {
      SourceError(source, "#include without file name");
      return qfalse;
    } // end else
#ifdef QUAKE
    if (!script) {
      Com_Memset(&file, 0, sizeof(foundfile_t));
      script = LoadScriptFile(path);
      if (script)
        strncpy(script->filename, path, MAX_PATH);
    }  // end if
#endif // QUAKE
    if (!script) {
#ifdef SCREWUP
      SourceWarning(source, "file %s not found", path);
      return qtrue;
#else
      SourceError(source, "file %s not found", path);
      return qfalse;
#endif // SCREWUP
    }  // end if
  PC_PushScript(source, script);
  return qtrue;
} // end of the function PC_Directive_include

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_ReadDefineParms(source_t *source, define_t *define, token_t **parms,
                       int maxparms)
{
  token_t token, *t, *last;
  int i, done, lastcomma, numparms, indent;

    if (!PC_ReadSourceToken(source, &token)) {
      SourceError(source, "define %s missing parms", define->name);
      return qfalse;
    } // end if
    //
    if (define->numparms > maxparms) {
      SourceError(source, "define with more than %d parameters", maxparms);
      return qfalse;
    } // end if
  //
  for (i = 0; i < define->numparms; i++)
    parms[i] = NULL;
    // if no leading "("
    if (strcmp(token.string, "(")) {
      PC_UnreadSourceToken(source, &token);
      SourceError(source, "define %s missing parms", define->name);
      return qfalse;
    } // end if
    // read the define parameters
    for (done = 0, numparms = 0, indent = 0; !done;) {
        if (numparms >= maxparms) {
          SourceError(source, "define %s with too many parms", define->name);
          return qfalse;
        } // end if
        if (numparms >= define->numparms) {
          SourceWarning(source, "define %s has too many parms", define->name);
          return qfalse;
        } // end if
      parms[numparms] = NULL;
      lastcomma = 1;
      last = NULL;
        while (!done) {
            //
            if (!PC_ReadSourceToken(source, &token)) {
              SourceError(source, "define %s incomplete", define->name);
              return qfalse;
            } // end if
            //
            if (!strcmp(token.string, ",")) {
                if (indent <= 0) {
                  if (lastcomma)
                    SourceWarning(source, "too many comma's");
                  lastcomma = 1;
                  break;
                } // end if
            }     // end if
          lastcomma = 0;
            //
            if (!strcmp(token.string, "(")) {
              indent++;
              continue;
            } // end if
            else if (!strcmp(token.string, ")")) {
                if (--indent <= 0) {
                    if (!parms[define->numparms - 1]) {
                      SourceWarning(source, "too few define parms");
                    } // end if
                  done = 1;
                  break;
                } // end if
            }     // end if
            //
            if (numparms < define->numparms) {
              //
              t = PC_CopyToken(&token);
              t->next = NULL;
              if (last)
                last->next = t;
              else
                parms[numparms] = t;
              last = t;
            } // end if
        }     // end while
      numparms++;
    } // end for
  return qtrue;
} // end of the function PC_ReadDefineParms

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_ExpandBuiltinDefine(source_t *source, token_t *deftoken,
                           define_t *define, token_t **firsttoken,
                           token_t **lasttoken)
{
  token_t *token;
  unsigned long t; //	time_t t; //to prevent LCC warning
  char *curtime;

  token = PC_CopyToken(deftoken);
    switch (define->builtin) {
    case BUILTIN_LINE:
      {
        sprintf(token->string, "%d", deftoken->line);
#ifdef NUMBERVALUE
        token->intvalue = deftoken->line;
        token->floatvalue = deftoken->line;
#endif // NUMBERVALUE
        token->type = TT_NUMBER;
        token->subtype = TT_DECIMAL | TT_INTEGER;
        *firsttoken = token;
        *lasttoken = token;
        break;
      } // end case
    case BUILTIN_FILE:
      {
        strcpy(token->string, source->scriptstack->filename);
        token->type = TT_NAME;
        token->subtype = strlen(token->string);
        *firsttoken = token;
        *lasttoken = token;
        break;
      } // end case
    case BUILTIN_DATE:
      {
        t = time(NULL);
        curtime = ctime(&t);
        strcpy(token->string, "\"");
        strncat(token->string, curtime + 4, 7);
        strncat(token->string + 7, curtime + 20, 4);
        strcat(token->string, "\"");
        free(curtime);
        token->type = TT_NAME;
        token->subtype = strlen(token->string);
        *firsttoken = token;
        *lasttoken = token;
        break;
      } // end case
    case BUILTIN_TIME:
      {
        t = time(NULL);
        curtime = ctime(&t);
        strcpy(token->string, "\"");
        strncat(token->string, curtime + 11, 8);
        strcat(token->string, "\"");
        free(curtime);
        token->type = TT_NAME;
        token->subtype = strlen(token->string);
        *firsttoken = token;
        *lasttoken = token;
        break;
      } // end case
    case BUILTIN_STDC:
    default:
      {
        *firsttoken = NULL;
        *lasttoken = NULL;
        break;
      } // end case
    }   // end switch
  return qtrue;
} // end of the function PC_ExpandBuiltinDefine

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_ExpandDefine(source_t *source, token_t *deftoken, define_t *define,
                    token_t **firsttoken, token_t **lasttoken)
{
  token_t *parms[MAX_DEFINEPARMS], *dt, *pt, *t;
  token_t *t1, *t2, *first, *last, *nextpt, token;
  int parmnum, i;

    // if it is a builtin define
    if (define->builtin) {
      return PC_ExpandBuiltinDefine(source, deftoken, define, firsttoken,
                                    lasttoken);
    } // end if
    // if the define has parameters
    if (define->numparms) {
      if (!PC_ReadDefineParms(source, define, parms, MAX_DEFINEPARMS))
        return qfalse;
#ifdef DEBUG_EVAL
        for (i = 0; i < define->numparms; i++) {
          Log_Write("define parms %d:", i);
            for (pt = parms[i]; pt; pt = pt->next) {
              Log_Write("%s", pt->string);
            } // end for
        }     // end for
#endif        // DEBUG_EVAL
    }         // end if
  // empty list at first
  first = NULL;
  last = NULL;
    // create a list with tokens of the expanded define
    for (dt = define->tokens; dt; dt = dt->next) {
      parmnum = -1;
        // if the token is a name, it could be a define parameter
        if (dt->type == TT_NAME) {
          parmnum = PC_FindDefineParm(define, dt->string);
        } // end if
        // if it is a define parameter
        if (parmnum >= 0) {
            for (pt = parms[parmnum]; pt; pt = pt->next) {
              t = PC_CopyToken(pt);
              // add the token to the list
              t->next = NULL;
              if (last)
                last->next = t;
              else
                first = t;
              last = t;
            } // end for
        }     // end if
        else {
            // if stringizing operator
            if (dt->string[0] == '#' && dt->string[1] == '\0') {
              // the stringizing operator must be followed by a define parameter
              if (dt->next)
                parmnum = PC_FindDefineParm(define, dt->next->string);
              else
                parmnum = -1;
                //
                if (parmnum >= 0) {
                  // step over the stringizing operator
                  dt = dt->next;
                    // stringize the define parameter tokens
                    if (!PC_StringizeTokens(parms[parmnum], &token)) {
                      SourceError(source, "can't stringize tokens");
                      return qfalse;
                    } // end if
                  t = PC_CopyToken(&token);
                } // end if
                else {
                  SourceWarning(
                      source, "stringizing operator without define parameter");
                  continue;
                } // end if
            }     // end if
            else {
              t = PC_CopyToken(dt);
            } // end else
          // add the token to the list
          t->next = NULL;
          if (last)
            last->next = t;
          else
            first = t;
          last = t;
        } // end else
    }     // end for
    // check for the merging operator
    for (t = first; t;) {
        if (t->next) {
            // if the merging operator
            if (t->next->string[0] == '#' && t->next->string[1] == '#') {
              t1 = t;
              t2 = t->next->next;
                if (t2) {
                    if (!PC_MergeTokens(t1, t2)) {
                      SourceError(source, "can't merge %s with %s", t1->string,
                                  t2->string);
                      return qfalse;
                    } // end if
                  PC_FreeToken(t1->next);
                  t1->next = t2->next;
                  if (t2 == last)
                    last = t1;
                  PC_FreeToken(t2);
                  continue;
                } // end if
            }     // end if
        }         // end if
      t = t->next;
    } // end for
  // store the first and last token of the list
  *firsttoken = first;
  *lasttoken = last;
    // free all the parameter tokens
    for (i = 0; i < define->numparms; i++) {
        for (pt = parms[i]; pt; pt = nextpt) {
          nextpt = pt->next;
          PC_FreeToken(pt);
        } // end for
    }     // end for
  //
  return qtrue;
} // end of the function PC_ExpandDefine

//============================================================================
// reads a token from the current line, continues reading on the next
// line only if a backslash '\' is encountered.
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_ReadLine(source_t *source, token_t *token)
{
  int crossline;

  crossline = 0;
    do {
      if (!PC_ReadSourceToken(source, token))
        return qfalse;

        if (token->linescrossed > crossline) {
          PC_UnreadSourceToken(source, token);
          return qfalse;
        } // end if
      crossline = 1;
    }
  while (!strcmp(token->string, "\\"));
  return qtrue;
} // end of the function PC_ReadLine

PC_ReadLineHandle(int handle, pc_token_s *pc_token)
{
  UNIMPLEMENTED();
}

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_pragma(source_t *source)
{
  token_t token;

  SourceWarning(source, "#pragma directive not supported");
  while (PC_ReadLine(source, &token))
    ;
  return qtrue;
} // end of the function PC_Directive_pragma

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_if_def(source_t *source, int type)
{
  token_t token;
  define_t *d;
  int skip;

    if (!PC_ReadLine(source, &token)) {
      SourceError(source, "#ifdef without name");
      return qfalse;
    } // end if
    if (token.type != TT_NAME) {
      PC_UnreadSourceToken(source, &token);
      SourceError(source, "expected name after #ifdef, found %s", token.string);
      return qfalse;
    } // end if
#if DEFINEHASHING
  d = PC_FindHashedDefine(source->definehash, token.string);
#else
  d = PC_FindDefine(source->defines, token.string);
#endif // DEFINEHASHING
  skip = (type == INDENT_IFDEF) == (d == NULL);
  PC_PushIndent(source, type, skip);
  return qtrue;
} // end of the function PC_Directiveif_def

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_ifndef(source_t *source)
{
  return PC_Directive_if_def(source, INDENT_IFNDEF);
} // end of the function PC_Directive_ifndef

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_ifdef(source_t *source)
{
  return PC_Directive_if_def(source, INDENT_IFDEF);
} // end of the function PC_Directive_ifdef

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_undef(source_t *source)
{
  token_t token;
  define_t *define, *lastdefine;
  int hash;

  if (source->skip > 0)
    return qtrue;
    //
    if (!PC_ReadLine(source, &token)) {
      SourceError(source, "undef without name");
      return qfalse;
    } // end if
    if (token.type != TT_NAME) {
      PC_UnreadSourceToken(source, &token);
      SourceError(source, "expected name, found %s", token.string);
      return qfalse;
    } // end if
#if DEFINEHASHING

  hash = PC_NameHash(token.string);
    for (lastdefine = NULL, define = source->definehash[hash]; define;
         define = define->hashnext) {
        if (!strcmp(define->name, token.string)) {
            if (define->flags & DEFINE_FIXED) {
              SourceWarning(source, "can't undef %s", token.string);
            } // end if
            else {
              if (lastdefine)
                lastdefine->hashnext = define->hashnext;
              else
                source->definehash[hash] = define->hashnext;
              PC_FreeDefine(define);
            } // end else
          break;
        } // end if
      lastdefine = define;
    }  // end for
#else  // DEFINEHASHING
    for (lastdefine = NULL, define = source->defines; define;
         define = define->next) {
        if (!strcmp(define->name, token.string)) {
            if (define->flags & DEFINE_FIXED) {
              SourceWarning(source, "can't undef %s", token.string);
            } // end if
            else {
              if (lastdefine)
                lastdefine->next = define->next;
              else
                source->defines = define->next;
              PC_FreeDefine(define);
            } // end else
          break;
        } // end if
      lastdefine = define;
    } // end for
#endif // DEFINEHASHING
  return qtrue;
} // end of the function PC_Directive_undef

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_ReadToken(source_t *source, token_t *token)
{
  define_t *define;

    while (1) {
      if (!PC_ReadSourceToken(source, token))
        return qfalse;
        // check for precompiler directives
        if (token->type == TT_PUNCTUATION && *token->string == '#') {
#ifdef QUAKEC
            if (!BuiltinFunction(source))
#endif // QUAKC
            {
              // read the precompiler directive
              if (!PC_ReadDirective(source))
                return qfalse;
              continue;
            } // end if
        }     // end if
        if (token->type == TT_PUNCTUATION && *token->string == '$') {
#ifdef QUAKEC
            if (!QuakeCMacro(source))
#endif // QUAKEC
            {
              // read the precompiler directive
              if (!PC_ReadDollarDirective(source))
                return qfalse;
              continue;
            } // end if
        }     // end if
        // recursively concatenate strings that are behind each other still
        // resolving defines
        if (token->type == TT_STRING) {
          token_t newtoken;
            if (PC_ReadToken(source, &newtoken)) {
                if (newtoken.type == TT_STRING) {
                  token->string[strlen(token->string) - 1] = '\0';
                    if (strlen(token->string) + strlen(newtoken.string + 1) +
                            1 >=
                        MAX_TOKEN) {
                      SourceError(source, "string longer than MAX_TOKEN %d\n",
                                  MAX_TOKEN);
                      return qfalse;
                    }
                  strcat(token->string, newtoken.string + 1);
                }
                else {
                  PC_UnreadToken(source, &newtoken);
                }
            }
        } // end if
      // if skipping source because of conditional compilation
      if (source->skip)
        continue;
        // if the token is a name
        if (token->type == TT_NAME) {
          // check if the name is a define macro
#if DEFINEHASHING
          define = PC_FindHashedDefine(source->definehash, token->string);
#else
          define = PC_FindDefine(source->defines, token->string);
#endif // DEFINEHASHING
       // if it is a define macro
            if (define) {
              // expand the defined macro
              if (!PC_ExpandDefineIntoSource(source, token, define))
                return qfalse;
              continue;
            } // end if
        }     // end if
      // copy token for unreading
      Com_Memcpy(&source->token, token, sizeof(token_t));
      // found a token
      return qtrue;
    } // end while
} // end of the function PC_ReadToken

//============================================================================
//
// Parameter:			-
// Returns:				-
// Changes Globals:		-
//============================================================================
int PC_ReadTokenHandle(int handle, pc_token_t *pc_token)
{
  token_t token;
  int ret;

  if (handle < 1 || handle >= MAX_SOURCEFILES)
    return 0;
  if (!sourceFiles[handle])
    return 0;

  ret = PC_ReadToken(sourceFiles[handle], &token);
  strcpy(pc_token->string, token.string);
  pc_token->type = token.type;
  pc_token->subtype = token.subtype;
  pc_token->intvalue = token.intvalue;
  pc_token->floatvalue = token.floatvalue;
  if (pc_token->type == TT_STRING)
    StripDoubleQuotes(pc_token->string);
  return ret;
} // end of the function PC_ReadTokenHandle

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_define(source_t *source)
{
  token_t token, *t, *last;
  define_t *define;

  if (source->skip > 0)
    return qtrue;
    //
    if (!PC_ReadLine(source, &token)) {
      SourceError(source, "#define without name");
      return qfalse;
    } // end if
    if (token.type != TT_NAME) {
      PC_UnreadSourceToken(source, &token);
      SourceError(source, "expected name after #define, found %s",
                  token.string);
      return qfalse;
    } // end if
    // check if the define already exists
#if DEFINEHASHING
  define = PC_FindHashedDefine(source->definehash, token.string);
#else
  define = PC_FindDefine(source->defines, token.string);
#endif // DEFINEHASHING
    if (define) {
        if (define->flags & DEFINE_FIXED) {
          SourceError(source, "can't redefine %s", token.string);
          return qfalse;
        } // end if
      SourceWarning(source, "redefinition of %s", token.string);
      // unread the define name before executing the #undef directive
      PC_UnreadSourceToken(source, &token);
      if (!PC_Directive_undef(source))
        return qfalse;
        // if the define was not removed (define->flags & DEFINE_FIXED)
#if DEFINEHASHING
      define = PC_FindHashedDefine(source->definehash, token.string);
#else
      define = PC_FindDefine(source->defines, token.string);
#endif // DEFINEHASHING
    }  // end if
  // allocate define
  define = (define_t *)GetMemory(sizeof(define_t) + strlen(token.string) + 1);
  Com_Memset(define, 0, sizeof(define_t));
  define->name = (char *)define + sizeof(define_t);
  strcpy(define->name, token.string);
  // add the define to the source
#if DEFINEHASHING
  PC_AddDefineToHash(define, source->definehash);
#else  // DEFINEHASHING
  define->next = source->defines;
  source->defines = define;
#endif // DEFINEHASHING
       // if nothing is defined, just return
  if (!PC_ReadLine(source, &token))
    return qtrue;
    // if it is a define with parameters
    if (!PC_WhiteSpaceBeforeToken(&token) && !strcmp(token.string, "(")) {
      // read the define parameters
      last = NULL;
        if (!PC_CheckTokenString(source, ")")) {
            while (1) {
                if (!PC_ReadLine(source, &token)) {
                  SourceError(source, "expected define parameter");
                  return qfalse;
                } // end if
                // if it isn't a name
                if (token.type != TT_NAME) {
                  SourceError(source, "invalid define parameter");
                  return qfalse;
                } // end if
                //
                if (PC_FindDefineParm(define, token.string) >= 0) {
                  SourceError(source, "two the same define parameters");
                  return qfalse;
                } // end if
              // add the define parm
              t = PC_CopyToken(&token);
              PC_ClearTokenWhiteSpace(t);
              t->next = NULL;
              if (last)
                last->next = t;
              else
                define->parms = t;
              last = t;
              define->numparms++;
                // read next token
                if (!PC_ReadLine(source, &token)) {
                  SourceError(source, "define parameters not terminated");
                  return qfalse;
                } // end if
              //
              if (!strcmp(token.string, ")"))
                break;
                // then it must be a comma
                if (strcmp(token.string, ",")) {
                  SourceError(source, "define not terminated");
                  return qfalse;
                } // end if
            }     // end while
        }         // end if
      if (!PC_ReadLine(source, &token))
        return qtrue;
    } // end if
  // read the defined stuff
  last = NULL;
    do {
      t = PC_CopyToken(&token);
        if (t->type == TT_NAME && !strcmp(t->string, define->name)) {
          SourceError(source, "recursive define (removed recursion)");
          continue;
        } // end if
      PC_ClearTokenWhiteSpace(t);
      t->next = NULL;
      if (last)
        last->next = t;
      else
        define->tokens = t;
      last = t;
    }
  while (PC_ReadLine(source, &token));
    //
    if (last) {
        // check for merge operators at the beginning or end
        if (!strcmp(define->tokens->string, "##") ||
            !strcmp(last->string, "##")) {
          SourceError(source, "define with misplaced ##");
          return qfalse;
        } // end if
    }     // end if
  return qtrue;
} // end of the function PC_Directive_define

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
define_t *PC_CopyDefine(source_t *source, define_t *define)
{
  define_t *newdefine;
  token_t *token, *newtoken, *lasttoken;

  newdefine =
      (define_t *)GetMemory(sizeof(define_t) + strlen(define->name) + 1);
  // copy the define name
  newdefine->name = (char *)newdefine + sizeof(define_t);
  strcpy(newdefine->name, define->name);
  newdefine->flags = define->flags;
  newdefine->builtin = define->builtin;
  newdefine->numparms = define->numparms;
  // the define is not linked
  newdefine->next = NULL;
  newdefine->hashnext = NULL;
  // copy the define tokens
  newdefine->tokens = NULL;
    for (lasttoken = NULL, token = define->tokens; token; token = token->next) {
      newtoken = PC_CopyToken(token);
      newtoken->next = NULL;
      if (lasttoken)
        lasttoken->next = newtoken;
      else
        newdefine->tokens = newtoken;
      lasttoken = newtoken;
    } // end for
  // copy the define parameters
  newdefine->parms = NULL;
    for (lasttoken = NULL, token = define->parms; token; token = token->next) {
      newtoken = PC_CopyToken(token);
      newtoken->next = NULL;
      if (lasttoken)
        lasttoken->next = newtoken;
      else
        newdefine->parms = newtoken;
      lasttoken = newtoken;
    } // end for
  return newdefine;
} // end of the function PC_CopyDefine

//============================================================================
//
// Parameter:			-
// Returns:				-
// Changes Globals:		-
//============================================================================
source_t *LoadSourceFile(const char *filename)
{
  source_t *source;
  script_t *script;

  PC_InitTokenHeap();

  script = LoadScriptFile(filename);
  if (!script)
    return NULL;

  script->next = NULL;

  source = (source_t *)GetMemory(sizeof(source_t));
  Com_Memset(source, 0, sizeof(source_t));

  strncpy(source->filename, filename, MAX_PATH);
  source->scriptstack = script;
  source->tokens = NULL;
  source->defines = NULL;
  source->indentstack = NULL;
  source->skip = 0;

#if DEFINEHASHING
  source->definehash = GetClearedMemory(DEFINEHASHSIZE * sizeof(define_t *));
#endif // DEFINEHASHING
  PC_AddGlobalDefinesToSource(source);
  return source;
} // end of the function LoadSourceFile

int PC_LoadSourceHandle(const char *filename)
{
  source_t *source;
  int i;

    for (i = 1; i < MAX_SOURCEFILES; i++) {
      if (!sourceFiles[i])
        break;
    } // end for
  if (i >= MAX_SOURCEFILES)
    return 0;
  PS_SetBaseFolder("");
  source = LoadSourceFile(filename);
  if (!source)
    return 0;
  sourceFiles[i] = source;
  return i;
} // end of the function PC_LoadSourceHandle

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Evaluate(source_t *source, signed long int *intvalue, double *floatvalue,
                int integer)
{
  token_t token, *firsttoken, *lasttoken;
  token_t *t, *nexttoken;
  define_t *define;
  int defined = qfalse;

  if (intvalue)
    *intvalue = 0;
  if (floatvalue)
    *floatvalue = 0;
    //
    if (!PC_ReadLine(source, &token)) {
      SourceError(source, "no value after #if/#elif");
      return qfalse;
    } // end if
  firsttoken = NULL;
  lasttoken = NULL;
    do {
        // if the token is a name
        if (token.type == TT_NAME) {
            if (defined) {
              defined = qfalse;
              t = PC_CopyToken(&token);
              t->next = NULL;
              if (lasttoken)
                lasttoken->next = t;
              else
                firsttoken = t;
              lasttoken = t;
            } // end if
            else if (!strcmp(token.string, "defined")) {
              defined = qtrue;
              t = PC_CopyToken(&token);
              t->next = NULL;
              if (lasttoken)
                lasttoken->next = t;
              else
                firsttoken = t;
              lasttoken = t;
            } // end if
            else {
              // then it must be a define
#if DEFINEHASHING
              define = PC_FindHashedDefine(source->definehash, token.string);
#else
              define = PC_FindDefine(source->defines, token.string);
#endif // DEFINEHASHING
                if (!define) {
                  SourceError(source, "can't evaluate %s, not defined",
                              token.string);
                  return qfalse;
                } // end if
              if (!PC_ExpandDefineIntoSource(source, &token, define))
                return qfalse;
            } // end else
        }     // end if
        // if the token is a number or a punctuation
        else if (token.type == TT_NUMBER || token.type == TT_PUNCTUATION) {
          t = PC_CopyToken(&token);
          t->next = NULL;
          if (lasttoken)
            lasttoken->next = t;
          else
            firsttoken = t;
          lasttoken = t;
        }    // end else
        else // can't evaluate the token
        {
          SourceError(source, "can't evaluate %s", token.string);
          return qfalse;
        } // end else
    }
  while (PC_ReadLine(source, &token));
  //
  if (!PC_EvaluateTokens(source, firsttoken, intvalue, floatvalue, integer))
    return qfalse;
    //
#ifdef DEBUG_EVAL
  Log_Write("eval:");
#endif // DEBUG_EVAL
    for (t = firsttoken; t; t = nexttoken) {
#ifdef DEBUG_EVAL
      Log_Write(" %s", t->string);
#endif // DEBUG_EVAL
      nexttoken = t->next;
      PC_FreeToken(t);
    } // end for
#ifdef DEBUG_EVAL
  if (integer)
    Log_Write("eval result: %d", *intvalue);
  else
    Log_Write("eval result: %f", *floatvalue);
#endif // DEBUG_EVAL
       //
  return qtrue;
} // end of the function PC_Evaluate

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_evalfloat(source_t *source)
{
  double value;
  token_t token;

  if (!PC_Evaluate(source, NULL, &value, qfalse))
    return qfalse;
  token.line = source->scriptstack->line;
  token.whitespace_p = source->scriptstack->script_p;
  token.endwhitespace_p = source->scriptstack->script_p;
  token.linescrossed = 0;
  sprintf(token.string, "%1.2f", fabs(value));
  token.type = TT_NUMBER;
  token.subtype = TT_FLOAT | TT_LONG | TT_DECIMAL;
  PC_UnreadSourceToken(source, &token);
  if (value < 0)
    UnreadSignToken(source);
  return qtrue;
} // end of the function PC_Directive_evalfloat

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_eval(source_t *source)
{
  signed long int value;
  token_t token;

  if (!PC_Evaluate(source, &value, NULL, qtrue))
    return qfalse;
  //
  token.line = source->scriptstack->line;
  token.whitespace_p = source->scriptstack->script_p;
  token.endwhitespace_p = source->scriptstack->script_p;
  token.linescrossed = 0;
  sprintf(token.string, "%d", abs(value));
  token.type = TT_NUMBER;
  token.subtype = TT_INTEGER | TT_LONG | TT_DECIMAL;
  PC_UnreadSourceToken(source, &token);
  if (value < 0)
    UnreadSignToken(source);
  return qtrue;
} // end of the function PC_Directive_eval

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_if(source_t *source)
{
  signed long int value;
  int skip;

  if (!PC_Evaluate(source, &value, NULL, qtrue))
    return qfalse;
  skip = (value == 0);
  PC_PushIndent(source, INDENT_IF, skip);
  return qtrue;
} // end of the function PC_Directive

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_Directive_elif(source_t *source)
{
  signed long int value;
  int type, skip;

  PC_PopIndent(source, &type, &skip);
    if (!type || type == INDENT_ELSE) {
      SourceError(source, "misplaced #elif");
      return qfalse;
    } // end if
  if (!PC_Evaluate(source, &value, NULL, qtrue))
    return qfalse;
  skip = (value == 0);
  PC_PushIndent(source, INDENT_ELIF, skip);
  return qtrue;
} // end of the function PC_Directive_elif

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_DollarEvaluate(source_t *source, signed long int *intvalue,
                      double *floatvalue, int integer)
{
  int indent, defined = qfalse;
  token_t token, *firsttoken, *lasttoken;
  token_t *t, *nexttoken;
  define_t *define;

  if (intvalue)
    *intvalue = 0;
  if (floatvalue)
    *floatvalue = 0;
    //
    if (!PC_ReadSourceToken(source, &token)) {
      SourceError(source, "no leading ( after $evalint/$evalfloat");
      return qfalse;
    } // end if
    if (!PC_ReadSourceToken(source, &token)) {
      SourceError(source, "nothing to evaluate");
      return qfalse;
    } // end if
  indent = 1;
  firsttoken = NULL;
  lasttoken = NULL;
    do {
        // if the token is a name
        if (token.type == TT_NAME) {
            if (defined) {
              defined = qfalse;
              t = PC_CopyToken(&token);
              t->next = NULL;
              if (lasttoken)
                lasttoken->next = t;
              else
                firsttoken = t;
              lasttoken = t;
            } // end if
            else if (!strcmp(token.string, "defined")) {
              defined = qtrue;
              t = PC_CopyToken(&token);
              t->next = NULL;
              if (lasttoken)
                lasttoken->next = t;
              else
                firsttoken = t;
              lasttoken = t;
            } // end if
            else {
              // then it must be a define
#if DEFINEHASHING
              define = PC_FindHashedDefine(source->definehash, token.string);
#else
              define = PC_FindDefine(source->defines, token.string);
#endif // DEFINEHASHING
                if (!define) {
                  SourceError(source, "can't evaluate %s, not defined",
                              token.string);
                  return qfalse;
                } // end if
              if (!PC_ExpandDefineIntoSource(source, &token, define))
                return qfalse;
            } // end else
        }     // end if
        // if the token is a number or a punctuation
        else if (token.type == TT_NUMBER || token.type == TT_PUNCTUATION) {
          if (*token.string == '(')
            indent++;
          else if (*token.string == ')')
            indent--;
          if (indent <= 0)
            break;
          t = PC_CopyToken(&token);
          t->next = NULL;
          if (lasttoken)
            lasttoken->next = t;
          else
            firsttoken = t;
          lasttoken = t;
        }    // end else
        else // can't evaluate the token
        {
          SourceError(source, "can't evaluate %s", token.string);
          return qfalse;
        } // end else
    }
  while (PC_ReadSourceToken(source, &token));
  //
  if (!PC_EvaluateTokens(source, firsttoken, intvalue, floatvalue, integer))
    return qfalse;
    //
#ifdef DEBUG_EVAL
  Log_Write("$eval:");
#endif // DEBUG_EVAL
    for (t = firsttoken; t; t = nexttoken) {
#ifdef DEBUG_EVAL
      Log_Write(" %s", t->string);
#endif // DEBUG_EVAL
      nexttoken = t->next;
      PC_FreeToken(t);
    } // end for
#ifdef DEBUG_EVAL
  if (integer)
    Log_Write("$eval result: %d", *intvalue);
  else
    Log_Write("$eval result: %f", *floatvalue);
#endif // DEBUG_EVAL
       //
  return qtrue;
} // end of the function PC_DollarEvaluate

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_DollarDirective_evalfloat(source_t *source)
{
  double value;
  token_t token;

  if (!PC_DollarEvaluate(source, NULL, &value, qfalse))
    return qfalse;
  token.line = source->scriptstack->line;
  token.whitespace_p = source->scriptstack->script_p;
  token.endwhitespace_p = source->scriptstack->script_p;
  token.linescrossed = 0;
  sprintf(token.string, "%1.2f", fabs(value));
  token.type = TT_NUMBER;
  token.subtype = TT_FLOAT | TT_LONG | TT_DECIMAL;
#ifdef NUMBERVALUE
  token.intvalue = (unsigned long)value;
  token.floatvalue = value;
#endif // NUMBERVALUE
  PC_UnreadSourceToken(source, &token);
  if (value < 0)
    UnreadSignToken(source);
  return qtrue;
} // end of the function PC_DollarDirective_evalfloat

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PC_DollarDirective_evalint(source_t *source)
{
  signed long int value;
  token_t token;

  if (!PC_DollarEvaluate(source, &value, NULL, qtrue))
    return qfalse;
  //
  token.line = source->scriptstack->line;
  token.whitespace_p = source->scriptstack->script_p;
  token.endwhitespace_p = source->scriptstack->script_p;
  token.linescrossed = 0;
  sprintf(token.string, "%d", abs(value));
  token.type = TT_NUMBER;
  token.subtype = TT_INTEGER | TT_LONG | TT_DECIMAL;
#ifdef NUMBERVALUE
  token.intvalue = value;
  token.floatvalue = value;
#endif // NUMBERVALUE
  PC_UnreadSourceToken(source, &token);
  if (value < 0)
    UnreadSignToken(source);
  return qtrue;
} // end of the function PC_DollarDirective_evalint
