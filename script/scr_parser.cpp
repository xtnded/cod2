int __cdecl Scr_GetSourceBuffer(char const * codePos)
{	UNIMPLEMENTED();
}

int __cdecl Scr_HasSourceFiles(void)
{	UNIMPLEMENTED();
}

unsigned int __cdecl Scr_GetClosestSourcePosOfType(int,unsigned int,int)
{	UNIMPLEMENTED();
}

char const * __cdecl Scr_GetOpcodePosOfType(int,unsigned int,unsigned int,int,unsigned int *)
{	UNIMPLEMENTED();
}

void __cdecl AddThreadStartOpcodePos(unsigned int sourcePos)
{	UNIMPLEMENTED();
}

void __cdecl RemoveOpcodePos()
{	UNIMPLEMENTED();
}

void __cdecl Scr_ShutdownOpcodeLookup()
{	UNIMPLEMENTED();
}

int __cdecl Scr_GetLineNum(int,unsigned int)
{	UNIMPLEMENTED();
}

unsigned int __cdecl Scr_GetPrevSourcePos(char const *,unsigned int)
{	UNIMPLEMENTED();
}

void __cdecl Scr_GetFileAndLine(char const *,char * *,int *)
{	UNIMPLEMENTED();
}

int __cdecl Scr_GetSourcePos(int,unsigned int,char *,int)
{	UNIMPLEMENTED();
}

int __cdecl Scr_GetSourcePosOfType(char const *,int,struct Scr_SourcePos_t *)
{	UNIMPLEMENTED();
}

void __cdecl AddOpcodePos(unsigned int sourcePos, int type)
{	UNIMPLEMENTED();
}

void __cdecl Scr_InitOpcodeLookup()
{	UNIMPLEMENTED();
}

void __cdecl Scr_GetCodePos(char const *,unsigned int,char *,int)
{	UNIMPLEMENTED();
}

void __cdecl Scr_PrintPrevCodePos(enum print_msg_type_t type, char const * codePos, unsigned int index)
{	UNIMPLEMENTED();
}

char * __cdecl Scr_AddSourceBuffer(char const * filename, char const * extFilename, char const * codePos, bool archive)
{	UNIMPLEMENTED();
}

void __cdecl RuntimeError(char const * codePos, unsigned int index, char const * msg, char const * dialogMessage)
{	UNIMPLEMENTED();
}

void __cdecl CompileError2(char const * codePos, char * msg, ...)
{	UNIMPLEMENTED();
}

int marker_scr_parser;
struct scrParserGlob_t scrParserGlob;
struct scrParserPub_t scrParserPub;
int __cdecl Scr_GetLineNumInternal(char const *,unsigned int,char const * *,int *)
{	UNIMPLEMENTED();
}

struct OpcodeLookup * __cdecl Scr_GetSourcePosOpcodeLookup(char const *)
{	UNIMPLEMENTED();
}

struct OpcodeLookup * __cdecl Scr_GetPrevSourcePosOpcodeLookup(char const *)
{	UNIMPLEMENTED();
}

int __cdecl Scr_GetLineInfo(char const *,unsigned int,int *,char *)
{	UNIMPLEMENTED();
}

void __cdecl Scr_PrintSourcePos(enum print_msg_type_t,char const *,char const *,unsigned int)
{	UNIMPLEMENTED();
}

struct SourceBufferInfo * __cdecl Scr_GetNewSourceBuffer(void)
{	UNIMPLEMENTED();
}

void __cdecl Scr_AddSourceBufferInternal(char const *,char const *,char *,int,bool,bool)
{	UNIMPLEMENTED();
}

char * __cdecl Scr_ReadFile(char const *,char const *,char const *,bool)
{	UNIMPLEMENTED();
}

void __cdecl RuntimeErrorInternal(enum print_msg_type_t,char const *,unsigned int,char const *)
{	UNIMPLEMENTED();
}

