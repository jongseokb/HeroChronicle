#pragma once

#ifdef _DEBUG
void DebugLog(const char* msg);
#else
// Release 빌드에서 호출해도 에러 안 나게
inline void DebugLog(const char*) {}
#endif
