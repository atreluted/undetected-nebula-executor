void __fastcall LoadEnvironment(__int64 L)
{
  __int64 State; // rdi
  __int64 v2; // rcx
  __int64 v3; // rdx
  unsigned __int64 v4; // rdx
  void *v5; // rcx
  __int64 v6; // rcx
  __int64 v7; // rdx
  unsigned __int64 v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rbx
  __int64 v11; // rbx
  void *v12; // rax
  _BYTE *v13; // rbx
  char *v14; // rbx
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rax
  void *v19; // rcx
  void *v20; // rcx
  void *v21; // rcx
  void *v22; // rcx
  __int128 v23; // [rsp+20h] [rbp-89h] BYREF
  __int128 v24; // [rsp+30h] [rbp-79h]
  __int128 v25; // [rsp+40h] [rbp-69h] BYREF
  __int64 v26; // [rsp+50h] [rbp-59h]
  unsigned __int64 v27; // [rsp+58h] [rbp-51h]
  __int128 v28; // [rsp+60h] [rbp-49h] BYREF
  __int64 v29; // [rsp+70h] [rbp-39h]
  unsigned __int64 v30; // [rsp+78h] [rbp-31h]
  __int128 v31; // [rsp+80h] [rbp-29h] BYREF
  __int64 v32; // [rsp+90h] [rbp-19h]
  unsigned __int64 v33; // [rsp+98h] [rbp-11h]
  _BYTE v34[32]; // [rsp+A0h] [rbp-9h] BYREF
  __int128 v35; // [rsp+C0h] [rbp+17h]
  __int64 v36; // [rsp+D0h] [rbp+27h]
  __int64 v37; // [rsp+D8h] [rbp+2Fh]
  __int64 v38; // [rsp+110h] [rbp+67h] BYREF

  v38 = L;
  State = qword_191318;
  sub_6AA90(qword_191318);
  RegisterClosure(State);
  RegisterHttp(State);
  RegisterScript(State);
  RegisterInstance(State);
  RegisterCrypt(State);
  RegisterFileSys(State);
  RegisterInput(State);
  RegisterCache(State);
  RegisterSignals(State);
  RegisterDebug(State);
  v23 = 0LL;
  *(_QWORD *)&v23 = sub_123490(0x790uLL);
  *(_QWORD *)&v24 = 0x78DLL;
  *((_QWORD *)&v24 + 1) = 0x78FLL;
  strcpy(
    (char *)v23,
    "\n"
    "local _wsenv = getgenv()\n"
    "_wsenv.WebSocket = _wsenv.WebSocket or {}\n"
    "\n"
    "local _sleep = (task and task.wait) or wait\n"
    "\n"
    "local function _wait_for_websocket_service(timeout_seconds)\n"
    "    local timeout = timeout_seconds or 15\n"
    "    local deadline = os.clock() + timeout\n"
    "\n"
    "    pcall(function()\n"
    "        if game and game.IsLoaded and not game:IsLoaded() then\n"
    "            game.Loaded:Wait()\n"
    "        end\n"
    "    end)\n"
    "\n"
    "    repeat\n"
    "        local ok, svc = pcall(function()\n"
    "            return game:GetService(\"WebSocketService\")\n"
    "        end)\n"
    "\n"
    "        if ok and svc and type(svc.CreateClient) == \"function\" then\n"
    "            return svc\n"
    "        end\n"
    "\n"
    "        _sleep(0.1)\n"
    "    until os.clock() >= deadline\n"
    "\n"
    "    return nil\n"
    "end\n"
    "\n"
    "_wsenv.WebSocket.connect = function(u)\n"
    "    if type(u) ~= \"string\" then\n"
    "        error(\"Invalid WebSocket URL: expected string\")\n"
    "    end\n"
    "\n"
    "    if u == \"ws://\" or u == \"wss://\" then\n"
    "        error(\"Invalid WebSocket URL: missing host/port\")\n"
    "    end\n"
    "\n"
    "    if not string.match(u, \"^wss?://\") then\n"
    "        error(\"Invalid WebSocket URL: expected ws:// or wss://\")\n"
    "    end\n"
    "\n"
    "    local service = _wait_for_websocket_service(15)\n"
    "    if not service then\n"
    "        error(\"WebSocketService unavailable: timed out waiting for service readiness\")\n"
    "    end\n"
    "\n"
    "    local last_error = \"unknown error\"\n"
    "    for _ = 1, 40 do\n"
    "        local ok, result = pcall(function()\n"
    "            return service:CreateClient(u)\n"
    "        end)\n"
    "\n"
    "        if ok and result then\n"
    "            local client = result\n"
    "            return {\n"
    "                OnMessage = client.MessageReceived,\n"
    "                OnClose = client.Closed,\n"
    "                Send = function(self, message)\n"
    "                    client:Send(message)\n"
    "                end,\n"
    "                Close = function(self)\n"
    "                    client:Close()\n"
    "                end\n"
    "            }\n"
    "        end\n"
    "\n"
    "        last_error = tostring(result)\n"
    "        _sleep(0.1)\n"
    "    end\n"
    "\n"
    "    error(\"Failed to create WebSocket client: \" .. last_error)\n"
    "end\n");
  v3 = qword_18E1E8;
  if ( qword_18E1E8 == qword_18E1F0 )
  {
    sub_36B10(v2, qword_18E1E8, &v23);
    v4 = *((_QWORD *)&v24 + 1);
  }
  else
  {
    *(_OWORD *)qword_18E1E8 = v23;
    *(_OWORD *)(v3 + 0x10) = v24;
    v4 = 0xFLL;
    LOBYTE(v23) = 0;
    qword_18E1E8 += 0x20LL;
  }
  if ( v4 > 0xF )
  {
    v5 = (void *)v23;
    if ( v4 + 1 >= 0x1000 )
    {
      if ( (unsigned __int64)(v23 - *(_QWORD *)(v23 - 8) - 8) > 0x1F )
        goto LABEL_43;
      v5 = *(void **)(v23 - 8);
    }
    j_j_free_0(v5);
  }
  RegisterScriptables(State);
  RegisterCache1(State);
  RegisterMethods(State);
  RegisterHooks(State);
  sub_6AA90(State);
  if ( (*(_BYTE *)State & 4) != 0 )
  {
    *(_BYTE *)State &= ~4u;
    v6 = *(_QWORD *)(State + 0x60);
    *(_QWORD *)(State + 0x10) = *(_QWORD *)(v6 + 0x28);
    *(_QWORD *)(v6 + 0x28) = State;
  }
  if ( byte_18D2A0 )
  {
    v7 = *(_QWORD *)(State + 0x68);
    if ( (unsigned __int64)(v7 + 0x10) > *(_QWORD *)(*(_QWORD *)(State + 0x50) + 8LL) )
    {
      if ( ((v7 - *(_QWORD *)(State + 0x70)) >> 4) + 1 > 0x1F40
        || *(_QWORD *)(State + 0x48) - v7 <= 0x10 && (LODWORD(v38) = 1, (unsigned int)sub_67C80(State, sub_57C00, &v38)) )
      {
        sub_70990(State, "stack overflow");
        sub_59D90(State);
      }
      v8 = *(_QWORD *)(State + 0x68) + 0x10LL;
      v9 = *(_QWORD *)(State + 0x50);
      if ( *(_QWORD *)(v9 + 8) < v8 )
        *(_QWORD *)(v9 + 8) = v8;
    }
  }
  *(_OWORD *)*(_QWORD *)(State + 0x68) = *(_OWORD *)sub_57930(State, 0xFFFFD8EELL);
  *(_QWORD *)(State + 0x68) += 0x10LL;
  v10 = sub_57930(State, 0xFFFFD8EELL);
  *(_QWORD *)&v23 = sub_722C0(State, &unk_166F48, 2LL);
  HIDWORD(v23) = 6;
  sub_80BD0(State, v10, &v23, *(_QWORD *)(State + 0x68) - 0x10LL);
  *(_QWORD *)(State + 0x68) -= 0x10LL;
  sub_59320(State, 0LL, 0LL);
  v11 = sub_57930(State, 0xFFFFD8EELL);
  *(_QWORD *)&v23 = sub_722C0(State, "shared", 6LL);
  HIDWORD(v23) = 6;
  sub_80BD0(State, v11, &v23, *(_QWORD *)(State + 0x68) - 0x10LL);
  *(_QWORD *)(State + 0x68) -= 0x10LL;
  v31 = 0LL;
  v32 = 0LL;
  v33 = 0LL;
  v12 = sub_123490(0x1D77uLL);
  if ( !v12 )
LABEL_43:
    __fastfail(5u);
  v13 = (_BYTE *)(((unsigned __int64)v12 + 0x27) & 0xFFFFFFFFFFFFFFE0uLL);
  *((_QWORD *)v13 + 0xFFFFFFFF) = v12;
  *(_QWORD *)&v31 = v13;
  v32 = 0x1D4BLL;
  v33 = 0x1D4FLL;
  memcpy(v13, aGetgenvFilterg, 0x1D4BuLL);
  v13[0x1D4B] = 0;
  v28 = 0LL;
  *(_QWORD *)&v28 = sub_123490(0x70uLL);
  v29 = 0x6FLL;
  v30 = 0x6FLL;
  strcpy(
    (char *)v28,
    "loadstring(game:HttpGet('https://raw.githubusercontent.com/aiunc-droid/test/refs/heads/main/decompile.luau'))()");
  v35 = 0LL;
  v14 = (char *)sub_123490(0x90uLL);
  *(_QWORD *)&v35 = v14;
  v36 = 0x8BLL;
  v37 = 0x8FLL;
  strcpy(
    v14,
    "setfflag(\"InstanceDirectAccess\", false)\n"
    "setfflag(\"LuauUdataDirectAccess6\", false)\n"
    "game:GetService(\"TeleportService\"):Teleport(game.PlaceId)");
  v25 = 0LL;
  *(_QWORD *)&v25 = sub_123490(0x70uLL);
  v26 = 0x6BLL;
  v27 = 0x6FLL;
  strcpy(
    (char *)v25,
    "loadstring(HttpGet('https://raw.githubusercontent.com/loopmetamethod/executor/refs/heads/main/env.luau'))()");
  v23 = 0LL;
  *(_QWORD *)&v23 = sub_123490(0x70uLL);
  *(_QWORD *)&v24 = 0x6FLL;
  *((_QWORD *)&v24 + 1) = 0x6FLL;
  strcpy(
    (char *)v23,
    "loadstring(HttpGet('https://raw.githubusercontent.com/loopmetamethod/executor/refs/heads/main/drawing.luau'))()");
  v15 = sub_8B90(v34, &v28);
  sub_C3460(v15);
  v16 = sub_8B90(v34, &v31);
  sub_C3460(v16);
  v17 = sub_8B90(v34, &v25);
  sub_C3460(v17);
  v18 = sub_8B90(v34, &v23);
  sub_C3460(v18);
  if ( *((_QWORD *)&v24 + 1) > 0xFuLL )
  {
    v19 = (void *)v23;
    if ( (unsigned __int64)(*((_QWORD *)&v24 + 1) + 1LL) >= 0x1000 )
    {
      if ( (unsigned __int64)(v23 - *(_QWORD *)(v23 - 8) - 8) > 0x1F )
        __fastfail(5u);
      v19 = *(void **)(v23 - 8);
    }
    j_j_free_0(v19);
  }
  if ( v27 > 0xF )
  {
    v20 = (void *)v25;
    if ( v27 + 1 >= 0x1000 )
    {
      if ( (unsigned __int64)(v25 - *(_QWORD *)(v25 - 8) - 8) > 0x1F )
        __fastfail(5u);
      v20 = *(void **)(v25 - 8);
    }
    j_j_free_0(v20);
  }
  j_j_free_0(v14);
  if ( v30 > 0xF )
  {
    v21 = (void *)v28;
    if ( v30 + 1 >= 0x1000 )
    {
      if ( (unsigned __int64)(v28 - *(_QWORD *)(v28 - 8) - 8) > 0x1F )
        __fastfail(5u);
      v21 = *(void **)(v28 - 8);
    }
    j_j_free_0(v21);
  }
  if ( v33 > 0xF )
  {
    v22 = (void *)v31;
    if ( v33 + 1 < 0x1000 )
    {
LABEL_38:
      j_j_free_0(v22);
      return;
    }
    if ( (unsigned __int64)(v31 - *(_QWORD *)(v31 - 8) - 8) <= 0x1F )
    {
      v22 = *(void **)(v31 - 8);
      goto LABEL_38;
    }
    goto LABEL_43;
  }
}
