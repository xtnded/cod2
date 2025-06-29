CL_SetServerInfo(serverInfo_t *server, char const *info, int ping) {
  UNIMPLEMENTED();
}

CL_SetServerInfoByAddress(netadr_t, char const *, int) { UNIMPLEMENTED(); }

CL_ServerInfoPacket(netadr_t from, msg_t *msg, int time) { UNIMPLEMENTED(); }

CL_CDKeyValidate(char const *key, char const *checksum) { UNIMPLEMENTED(); }

CL_SortGlobalServers() { UNIMPLEMENTED(); }

CL_RconInit() { UNIMPLEMENTED(); }

CL_Rcon_f() { UNIMPLEMENTED(); }

CL_ServerStatusResponse(netadr_t from, msg_t *msg) { UNIMPLEMENTED(); }

CL_ResetPlayerMuting(int clientIndex) { UNIMPLEMENTED(); }

CL_MutePlayer(int clientIndex) { UNIMPLEMENTED(); }

CL_IsPlayerMuted(int clientIndex) { UNIMPLEMENTED(); }

CL_ClearMutedList() { UNIMPLEMENTED(); }

CL_GlobalServers_f() { UNIMPLEMENTED(); }

CL_ServersResponsePacket(netadr_t from, msg_t *msg) { UNIMPLEMENTED(); }

CL_Ping_f() { UNIMPLEMENTED(); }

CL_Connect_f() { UNIMPLEMENTED(); }

CL_ServerStatus(char *serverAddress, char *serverStatusString, int maxLen) {
  UNIMPLEMENTED();
}

CL_ServerStatus_f() { UNIMPLEMENTED(); }
