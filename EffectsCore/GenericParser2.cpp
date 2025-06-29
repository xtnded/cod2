int marker_GenericParser2;
GPValue::GetTopValue() { UNIMPLEMENTED(); }

GPValue::IsList() { UNIMPLEMENTED(); }

GPGroup::SortObject(GPObject *object, GPObject **unsortedList,
                    GPObject **sortedList, GPObject **lastObject) {
  UNIMPLEMENTED();
}

GPGroup::Clean() { UNIMPLEMENTED(); }

GenericParser2::GenericParser2() { UNIMPLEMENTED(); }

TextPool::AllocText(char *text, unsigned char addNULL, TextPool **poolPtr) {
  UNIMPLEMENTED();
}

GPGroup::AddGroup(char const *name, TextPool **textPool) { UNIMPLEMENTED(); }

GPValue::AddValue(char const *newValue, TextPool **textPool) {
  UNIMPLEMENTED();
}

GPGroup::AddPair(char const *name, char const *value, TextPool **textPool) {
  UNIMPLEMENTED();
}

GenericParser2::~GenericParser2() { UNIMPLEMENTED(); }

GPGroup::Parse(char **dataPtr, TextPool **textPool) { UNIMPLEMENTED(); }

GenericParser2::Parse(char **dataPtr, unsigned char cleanFirst,
                      unsigned char writeable) {
  UNIMPLEMENTED();
}
