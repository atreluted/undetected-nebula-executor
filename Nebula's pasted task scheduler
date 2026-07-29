char __fastcall InitScheduler(__int64 TpHandlerDatamodel)
{
  __int64 Datamodel; // rax
  void **v2; // rcx
  const CHAR *v3; // rcx
  _QWORD *ScriptContext; // rax
  void **v5; // rcx
  __int64 State; // rax
  __int64 Thread; // rax
  __int64 Thread_1; // rcx
  __int64 CState; // rax
  __int64 UserData; // rdx
  void **v11; // rbx
  void **v12; // rcx
  __int64 v13; // rbx
  __int64 v14; // rdi
  void **v16; // rcx
  void **v17; // rcx
  __int128 v18; // [rsp+20h] [rbp-48h] BYREF
  __int64 v19; // [rsp+30h] [rbp-38h]
  _OWORD v20[3]; // [rsp+38h] [rbp-30h] BYREF
  __int64 GStateArg; // [rsp+70h] [rbp+8h] BYREF

  Datamodel = TpHandlerDatamodel;
  if ( !TpHandlerDatamodel )
  {
    Datamodel = GetDatamodel();

    if ( !Datamodel )
    {
      v2 = &Buf1;

      if ( (unsigned __int64)qword_18E198 > 0xF )
        v2 = (void **)Buf1;

      if ( qword_18E190 == 0x19 && !memcmp(v2, "No valid datamodel found.", 0x19uLL) )
        return 0;

      cout(&Buf1, "No valid datamodel found.", 0x19uLL);
      r_print(3LL, "[Venza] scheduler: %s", "No valid datamodel found.");
      v3 = "No valid datamodel found.";
LABEL_49:

      OutputDebugStringA(v3);
      OutputDebugStringA("\n");

      return 0;
    }
  }

  ScriptContext = GetScriptContext(Datamodel);

  if ( !ScriptContext )
  {
    v5 = &Buf1;

    if ( (unsigned __int64)qword_18E198 > 0xF )
      v5 = (void **)Buf1;

    if ( qword_18E190 == 0x1D && !memcmp(v5, "No valid scriptcontext found.", 0x1DuLL) )
      return 0;

    cout(&Buf1, "No valid scriptcontext found.", 0x1DuLL);
    r_print(3LL, "[Venza] scheduler: %s", "No valid scriptcontext found.");
    v3 = "No valid scriptcontext found.";

    goto LABEL_49;
  }

  *((_BYTE *)ScriptContext + 0x909) = 1;
  GStateArg = 0LL;
  State = qword_191348(ScriptContext, &GStateArg, &GStateArg);

  if ( !State || !*(_QWORD *)(State + 0x78) )
  {
    v17 = &Buf1;

    if ( (unsigned __int64)qword_18E198 > 0xF )
      v17 = (void **)Buf1;

    if ( qword_18E190 == 0x18 && !memcmp(v17, "No valid luastate found.", 0x18uLL) )
      return 0;

    cout(&Buf1, "No valid luastate found.", 0x18uLL);
    r_print(3LL, "[Venza] scheduler: %s", "No valid luastate found.");
    v3 = "No valid luastate found.";
    goto LABEL_49;
  }

  Thread = lua_newthread(State);
  CurState = Thread;

  if ( !Thread || !*(_QWORD *)(Thread + 0x78) )
  {
    v16 = &Buf1;

    if ( (unsigned __int64)qword_18E198 > 0xF )
      v16 = (void **)Buf1;

    if ( qword_18E190 == 0x1A && !memcmp(v16, "Failed to create a thread.", 0x1AuLL) )
      return 0;

    cout(&Buf1, "Failed to create a thread.", 0x1AuLL);
    r_print(3LL, "[Venza] scheduler: %s", "Failed to create a thread.");
    v3 = "Failed to create a thread.";

    goto LABEL_49;
  }

  _InterlockedIncrement64(&qword_191320);

  CState = CurState;

  if ( CurState )
  {
    UserData = *(_QWORD *)(CurState + 0x78);

    if ( UserData )
    {
      Thread_1 = MCaps;

      *(_QWORD *)(UserData + 0x78) = 8LL;       // set identity 😭
      *(_QWORD *)(*(_QWORD *)(CState + 0x78) + 0x40LL) = Thread_1;
    }
  }

  LoadEnvironment(Thread_1);

  v11 = &Buf1;

  if ( !(unsigned __int8)sub_C2A20() )
  {
    v12 = &Buf1;

    if ( (unsigned __int64)qword_18E198 > 0xF )
      v12 = (void **)Buf1;

    if ( qword_18E190 != 0x2E || memcmp(v12, "failed to connect the Heartbeat execution hook", 0x2EuLL) )
    {
      cout(&Buf1, "failed to connect the Heartbeat execution hook", 0x2EuLL);
      r_print(3LL, "[Venza] scheduler: %s", "failed to connect the Heartbeat execution hook");
      OutputDebugStringA("failed to connect the Heartbeat execution hook");
      OutputDebugStringA("\n");
    }

    CurState = 0LL;

    return 0;
  }

  qword_18E190 = 0LL;

  if ( (unsigned __int64)qword_18E198 > 0xF )
    v11 = (void **)Buf1;

  *(_BYTE *)v11 = 0;
  r_print(1LL, "Venza Has Loaded.");

  if ( qword_191308 )
  {
    v18 = 0LL;
    v19 = 0LL;

    if ( Mtx_lock((_Mtx_t)&unk_18C920) )
    {
      std::_Throw_Cpp_error(5);
      __debugbreak();
    }

    if ( dword_18C96C == 0x7FFFFFFF )
    {
      dword_18C96C = 0x7FFFFFFE;
      std::_Throw_Cpp_error(6);
      __debugbreak();
    }

    v13 = xmmword_18E1F8;
    v18 = xmmword_18E1F8;
    v14 = *((_QWORD *)&xmmword_18E1F8 + 1);

    xmmword_18E1F8 = 0uLL;
    v19 = qword_18E208;
    qword_18E208 = 0LL;

    Mtx_unlock((_Mtx_t)&unk_18C920);

    for ( ; v13 != v14; v13 += 0x20LL )
    {
      v20[0] = *(_OWORD *)v13;
      v20[1] = *(_OWORD *)(v13 + 0x10);

      *(_BYTE *)v13 = 0;
      *(_QWORD *)(v13 + 0x10) = 0LL;
      *(_QWORD *)(v13 + 0x18) = 0xFLL;

      sub_C3460(v20);
    }

    sub_BB70(&v18);
  }

  return 1;
}
