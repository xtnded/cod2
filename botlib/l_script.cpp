int marker_l_script;

//===========================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//===========================================================================
void PS_CreatePunctuationTable(script_t *script, punctuation_t *punctuations)
{
  int i;
  punctuation_t *p, *lastp, *newp;

  // get memory for the table
  if (!script->punctuationtable)
    script->punctuationtable =
        (punctuation_t **)GetMemory(256 * sizeof(punctuation_t *));
  Com_Memset(script->punctuationtable, 0, 256 * sizeof(punctuation_t *));
    // add the punctuations in the list to the punctuation table
    for (i = 0; punctuations[i].p; i++) {
      newp = &punctuations[i];
      lastp = NULL;
        // sort the punctuations in this table entry on length (longer
        // punctuations first)
        for (p = script->punctuationtable[(unsigned int)newp->p[0]]; p;
             p = p->next) {
            if (strlen(p->p) < strlen(newp->p)) {
              newp->next = p;
              if (lastp)
                lastp->next = newp;
              else
                script->punctuationtable[(unsigned int)newp->p[0]] = newp;
              break;
            } // end if
          lastp = p;
        } // end for
        if (!p) {
          newp->next = NULL;
          if (lastp)
            lastp->next = newp;
          else
            script->punctuationtable[(unsigned int)newp->p[0]] = newp;
        } // end if
    }     // end for
} // end of the function PS_CreatePunctuationTable

//===========================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//===========================================================================
void QDECL ScriptError(script_t *script, char *str, ...)
{
  char text[1024];
  va_list ap;

  if (script->flags & SCFL_NOERRORS)
    return;

  va_start(ap, str);
  vsprintf(text, str, ap);
  va_end(ap);
#ifdef BOTLIB
  botimport.Print(PRT_ERROR, "file %s, line %d: %s\n", script->filename,
                  script->line, text);
#endif // BOTLIB
#ifdef MEQCC
  printf("error: file %s, line %d: %s\n", script->filename, script->line, text);
#endif // MEQCC
#ifdef BSPC
  Log_Print("error: file %s, line %d: %s\n", script->filename, script->line,
            text);
#endif // BSPC
} // end of the function ScriptError

//===========================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//===========================================================================
void QDECL ScriptWarning(script_t *script, char *str, ...)
{
  char text[1024];
  va_list ap;

  if (script->flags & SCFL_NOWARNINGS)
    return;

  va_start(ap, str);
  vsprintf(text, str, ap);
  va_end(ap);
#ifdef BOTLIB
  botimport.Print(PRT_WARNING, "file %s, line %d: %s\n", script->filename,
                  script->line, text);
#endif // BOTLIB
#ifdef MEQCC
  printf("warning: file %s, line %d: %s\n", script->filename, script->line,
         text);
#endif // MEQCC
#ifdef BSPC
  Log_Print("warning: file %s, line %d: %s\n", script->filename, script->line,
            text);
#endif // BSPC
} // end of the function ScriptWarning

//============================================================================
// Reads an escape character.
//
// Parameter:				script		: script to read from
//								ch
//: place to store the read escape character
// Returns:					-
// Changes Globals:		-
//============================================================================
int PS_ReadEscapeCharacter(script_t *script, char *ch)
{
  int c, val, i;

  // step over the leading '\\'
  script->script_p++;
    // determine the escape character
    switch (*script->script_p) {
    case '\\':
      c = '\\';
      break;
    case 'n':
      c = '\n';
      break;
    case 'r':
      c = '\r';
      break;
    case 't':
      c = '\t';
      break;
    case 'v':
      c = '\v';
      break;
    case 'b':
      c = '\b';
      break;
    case 'f':
      c = '\f';
      break;
    case 'a':
      c = '\a';
      break;
    case '\'':
      c = '\'';
      break;
    case '\"':
      c = '\"';
      break;
    case '\?':
      c = '\?';
      break;
    case 'x':
      {
        script->script_p++;
          for (i = 0, val = 0;; i++, script->script_p++) {
            c = *script->script_p;
            if (c >= '0' && c <= '9')
              c = c - '0';
            else if (c >= 'A' && c <= 'Z')
              c = c - 'A' + 10;
            else if (c >= 'a' && c <= 'z')
              c = c - 'a' + 10;
            else
              break;
            val = (val << 4) + c;
          } // end for
        script->script_p--;
          if (val > 0xFF) {
            ScriptWarning(script, "too large value in escape character");
            val = 0xFF;
          } // end if
        c = val;
        break;
      }      // end case
    default: // NOTE: decimal ASCII code, NOT octal
      {
        if (*script->script_p < '0' || *script->script_p > '9')
          ScriptError(script, "unknown escape char");
          for (i = 0, val = 0;; i++, script->script_p++) {
            c = *script->script_p;
            if (c >= '0' && c <= '9')
              c = c - '0';
            else
              break;
            val = val * 10 + c;
          } // end for
        script->script_p--;
          if (val > 0xFF) {
            ScriptWarning(script, "too large value in escape character");
            val = 0xFF;
          } // end if
        c = val;
        break;
      } // end default
    }   // end switch
  // step over the escape character or the last digit of the number
  script->script_p++;
  // store the escape character
  *ch = c;
  // succesfully read escape character
  return 1;
} // end of the function PS_ReadEscapeCharacter

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
void NumberValue(char *string, int subtype, unsigned long int *intvalue,
                 long double *floatvalue)
{
  unsigned long int dotfound = 0;

  *intvalue = 0;
  *floatvalue = 0;
    // floating point number
    if (subtype & TT_FLOAT) {
        while (*string) {
            if (*string == '.') {
              if (dotfound)
                return;
              dotfound = 10;
              string++;
            } // end if
            if (dotfound) {
              *floatvalue = *floatvalue + (long double)(*string - '0') /
                                              (long double)dotfound;
              dotfound *= 10;
            } // end if
            else {
              *floatvalue = *floatvalue * 10.0 + (long double)(*string - '0');
            } // end else
          string++;
        } // end while
      *intvalue = (unsigned long)*floatvalue;
    } // end if
    else if (subtype & TT_DECIMAL) {
      while (*string)
        *intvalue = *intvalue * 10 + (*string++ - '0');
      *floatvalue = *intvalue;
    } // end else if
    else if (subtype & TT_HEX) {
      // step over the leading 0x or 0X
      string += 2;
        while (*string) {
          *intvalue <<= 4;
          if (*string >= 'a' && *string <= 'f')
            *intvalue += *string - 'a' + 10;
          else if (*string >= 'A' && *string <= 'F')
            *intvalue += *string - 'A' + 10;
          else
            *intvalue += *string - '0';
          string++;
        } // end while
      *floatvalue = *intvalue;
    } // end else if
    else if (subtype & TT_OCTAL) {
      // step over the first zero
      string += 1;
      while (*string)
        *intvalue = (*intvalue << 3) + (*string++ - '0');
      *floatvalue = *intvalue;
    } // end else if
    else if (subtype & TT_BINARY) {
      // step over the leading 0b or 0B
      string += 2;
      while (*string)
        *intvalue = (*intvalue << 1) + (*string++ - '0');
      *floatvalue = *intvalue;
    } // end else if
} // end of the function NumberValue

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PS_ReadNumber(script_t *script, token_t *token)
{
  int len = 0, i;
  int octal, dot;
  char c;
  //	unsigned long int intvalue = 0;
  //	long double floatvalue = 0;

  token->type = TT_NUMBER;
    // check for a hexadecimal number
    if (*script->script_p == '0' &&
        (*(script->script_p + 1) == 'x' || *(script->script_p + 1) == 'X')) {
      token->string[len++] = *script->script_p++;
      token->string[len++] = *script->script_p++;
      c = *script->script_p;
        // hexadecimal
        while ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
               (c >= 'A' && c <= 'A')) {
          token->string[len++] = *script->script_p++;
            if (len >= MAX_TOKEN) {
              ScriptError(script,
                          "hexadecimal number longer than MAX_TOKEN = %d",
                          MAX_TOKEN);
              return 0;
            } // end if
          c = *script->script_p;
        } // end while
      token->subtype |= TT_HEX;
    } // end if
#ifdef BINARYNUMBERS
    // check for a binary number
    else if (*script->script_p == '0' && (*(script->script_p + 1) == 'b' ||
                                          *(script->script_p + 1) == 'B')) {
      token->string[len++] = *script->script_p++;
      token->string[len++] = *script->script_p++;
      c = *script->script_p;
        // binary
        while (c == '0' || c == '1') {
          token->string[len++] = *script->script_p++;
            if (len >= MAX_TOKEN) {
              ScriptError(script, "binary number longer than MAX_TOKEN = %d",
                          MAX_TOKEN);
              return 0;
            } // end if
          c = *script->script_p;
        } // end while
      token->subtype |= TT_BINARY;
    }    // end if
#endif   // BINARYNUMBERS
    else // decimal or octal integer or floating point number
    {
      octal = qfalse;
      dot = qfalse;
      if (*script->script_p == '0')
        octal = qtrue;
        while (1) {
          c = *script->script_p;
          if (c == '.')
            dot = qtrue;
          else if (c == '8' || c == '9')
            octal = qfalse;
          else if (c < '0' || c > '9')
            break;
          token->string[len++] = *script->script_p++;
            if (len >= MAX_TOKEN - 1) {
              ScriptError(script, "number longer than MAX_TOKEN = %d",
                          MAX_TOKEN);
              return 0;
            } // end if
        }     // end while
      if (octal)
        token->subtype |= TT_OCTAL;
      else
        token->subtype |= TT_DECIMAL;
      if (dot)
        token->subtype |= TT_FLOAT;
    } // end else
    for (i = 0; i < 2; i++) {
      c = *script->script_p;
        // check for a LONG number
        if ((c == 'l' || c == 'L') // bk001204 - brackets
            && !(token->subtype & TT_LONG)) {
          script->script_p++;
          token->subtype |= TT_LONG;
        } // end if
        // check for an UNSIGNED number
        else if ((c == 'u' || c == 'U') // bk001204 - brackets
                 && !(token->subtype & (TT_UNSIGNED | TT_FLOAT))) {
          script->script_p++;
          token->subtype |= TT_UNSIGNED;
        } // end if
    }     // end for
  token->string[len] = '\0';
#ifdef NUMBERVALUE
  NumberValue(token->string, token->subtype, &token->intvalue,
              &token->floatvalue);
#endif // NUMBERVALUE
  if (!(token->subtype & TT_FLOAT))
    token->subtype |= TT_INTEGER;
  return 1;
} // end of the function PS_ReadNumber

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
void StripDoubleQuotes(char *string)
{
    if (*string == '\"') {
      strcpy(string, string + 1);
    } // end if
    if (string[strlen(string) - 1] == '\"') {
      string[strlen(string) - 1] = '\0';
    } // end if
} // end of the function StripDoubleQuotes

//============================================================================
// returns true if at the end of the script
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int EndOfScript(script_t *script)
{
  return script->script_p >= script->end_p;
} // end of the function EndOfScript

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
void FreeScript(script_t *script)
{
#ifdef PUNCTABLE
  if (script->punctuationtable)
    FreeMemory(script->punctuationtable);
#endif // PUNCTABLE
  FreeMemory(script);
} // end of the function FreeScript

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
script_t *LoadScriptFile(const char *filename)
{
#ifdef BOTLIB
  fileHandle_t fp;
  char pathname[MAX_QPATH];
#else
  FILE *fp;
#endif
  int length;
  void *buffer;
  script_t *script;

#ifdef BOTLIB
  if (strlen(basefolder))
    Com_sprintf(pathname, sizeof(pathname), "%s/%s", basefolder, filename);
  else
    Com_sprintf(pathname, sizeof(pathname), "%s", filename);
  length = botimport.FS_FOpenFile(pathname, &fp, FS_READ);
  if (!fp)
    return NULL;
#else
  fp = fopen(filename, "rb");
  if (!fp)
    return NULL;

  length = FileLength(fp);
#endif

  buffer = GetClearedMemory(sizeof(script_t) + length + 1);
  script = (script_t *)buffer;
  Com_Memset(script, 0, sizeof(script_t));
  strcpy(script->filename, filename);
  script->buffer = (char *)buffer + sizeof(script_t);
  script->buffer[length] = 0;
  script->length = length;
  // pointer in script buffer
  script->script_p = script->buffer;
  // pointer in script buffer before reading token
  script->lastscript_p = script->buffer;
  // pointer to end of script buffer
  script->end_p = &script->buffer[length];
  // set if there's a token available in script->token
  script->tokenavailable = 0;
  //
  script->line = 1;
  script->lastline = 1;
  //
  SetScriptPunctuations(script, NULL);
  //
#ifdef BOTLIB
  botimport.FS_Read(script->buffer, length, fp);
  botimport.FS_FCloseFile(fp);
#else
    if (fread(script->buffer, length, 1, fp) != 1) {
      FreeMemory(buffer);
      script = NULL;
    } // end if
  fclose(fp);
#endif
  //
  script->length = COM_Compress(script->buffer);

  return script;
} // end of the function LoadScriptFile

//============================================================================
// Reads C-like string. Escape characters are interpretted.
// Quotes are included with the string.
// Reads two strings with a white space between them as one string.
//
// Parameter:				script		: script to read from
//								token
//: buffer to store the string
// Returns:					qtrue when a string was read
// succesfully Changes Globals:		-
//============================================================================
int PS_ReadString(script_t *script, token_t *token, int quote)
{
  int len, tmpline;
  char *tmpscript_p;

  if (quote == '\"')
    token->type = TT_STRING;
  else
    token->type = TT_LITERAL;

  len = 0;
  // leading quote
  token->string[len++] = *script->script_p++;
    //
    while (1) {
        // minus 2 because trailing double quote and zero have to be appended
        if (len >= MAX_TOKEN - 2) {
          ScriptError(script, "string longer than MAX_TOKEN = %d", MAX_TOKEN);
          return 0;
        } // end if
        // if there is an escape character and
        // if escape characters inside a string are allowed
        if (*script->script_p == '\\' &&
            !(script->flags & SCFL_NOSTRINGESCAPECHARS)) {
            if (!PS_ReadEscapeCharacter(script, &token->string[len])) {
              token->string[len] = 0;
              return 0;
            } // end if
          len++;
        } // end if
        // if a trailing quote
        else if (*script->script_p == quote) {
          // step over the double quote
          script->script_p++;
          // if white spaces in a string are not allowed
          if (script->flags & SCFL_NOSTRINGWHITESPACES)
            break;
          //
          tmpscript_p = script->script_p;
          tmpline = script->line;
            // read unusefull stuff between possible two following strings
            if (!PS_ReadWhiteSpace(script)) {
              script->script_p = tmpscript_p;
              script->line = tmpline;
              break;
            } // end if
            // if there's no leading double qoute
            if (*script->script_p != quote) {
              script->script_p = tmpscript_p;
              script->line = tmpline;
              break;
            } // end if
          // step over the new leading double quote
          script->script_p++;
        } // end if
        else {
            if (*script->script_p == '\0') {
              token->string[len] = 0;
              ScriptError(script, "missing trailing quote");
              return 0;
            } // end if
            if (*script->script_p == '\n') {
              token->string[len] = 0;
              ScriptError(script, "newline inside string %s", token->string);
              return 0;
            } // end if
          token->string[len++] = *script->script_p++;
        } // end else
    }     // end while
  // trailing quote
  token->string[len++] = quote;
  // end string with a zero
  token->string[len] = '\0';
  // the sub type is the length of the string
  token->subtype = len;
  return 1;
} // end of the function PS_ReadString

//============================================================================
//
// Parameter:				-
// Returns:					-
// Changes Globals:		-
//============================================================================
int PS_ReadToken(script_t *script, token_t *token)
{
    // if there is a token available (from UnreadToken)
    if (script->tokenavailable) {
      script->tokenavailable = 0;
      Com_Memcpy(token, &script->token, sizeof(token_t));
      return 1;
    } // end if
  // save script pointer
  script->lastscript_p = script->script_p;
  // save line counter
  script->lastline = script->line;
  // clear the token stuff
  Com_Memset(token, 0, sizeof(token_t));
  // start of the white space
  script->whitespace_p = script->script_p;
  token->whitespace_p = script->script_p;
  // read unusefull stuff
  if (!PS_ReadWhiteSpace(script))
    return 0;
  // end of the white space
  script->endwhitespace_p = script->script_p;
  token->endwhitespace_p = script->script_p;
  // line the token is on
  token->line = script->line;
  // number of lines crossed before token
  token->linescrossed = script->line - script->lastline;
    // if there is a leading double quote
    if (*script->script_p == '\"') {
      if (!PS_ReadString(script, token, '\"'))
        return 0;
    } // end if
    // if an literal
    else if (*script->script_p == '\'') {
      // if (!PS_ReadLiteral(script, token)) return 0;
      if (!PS_ReadString(script, token, '\''))
        return 0;
    } // end if
    // if there is a number
    else if ((*script->script_p >= '0' && *script->script_p <= '9') ||
             (*script->script_p == '.' && (*(script->script_p + 1) >= '0' &&
                                           *(script->script_p + 1) <= '9'))) {
      if (!PS_ReadNumber(script, token))
        return 0;
    } // end if
    // if this is a primitive script
    else if (script->flags & SCFL_PRIMITIVE) {
      return PS_ReadPrimitive(script, token);
    } // end else if
    // if there is a name
    else if ((*script->script_p >= 'a' && *script->script_p <= 'z') ||
             (*script->script_p >= 'A' && *script->script_p <= 'Z') ||
             *script->script_p == '_') {
      if (!PS_ReadName(script, token))
        return 0;
    } // end if
    // check for punctuations
    else if (!PS_ReadPunctuation(script, token)) {
      ScriptError(script, "can't read token");
      return 0;
    } // end if
  // copy the token into the script structure
  Com_Memcpy(&script->token, token, sizeof(token_t));
  // succesfully read a token
  return 1;
} // end of the function PS_ReadToken
