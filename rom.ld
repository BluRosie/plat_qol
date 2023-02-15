FillWindowPixelBuffer = 0x0201ADA4| 1;
ConvertNumToString = 0x02090184| 1;
StringPut = 0x020900D8| 1;
PutWindows = 0x0201A9A4| 1;/*0801A64C*/
FreeSystem = 0x02018238| 1;
sys_AllocMemory = 0x02018144 | 1;
SaveData_GetDexPtr = 0x02027560 | 1;
GetEventVar = 0x0203F098 |1;
GetSaveDataPtr = 0x0202D834 | 1;
SaveData_GetRepelPtr = 0x0202D9CC | 1;

//ClearReq = 0x021D1C30 | 1; /*to rewrite in code*/
//CheckReq = 0x021D1DA4 | 1; /*to rewrite in code*/
//SetReq = 0x021D1CAC | 1; /*to rewrite in code*/

EventSet_Script = 0x0203E880 | 1;
Player_MoveStateGet = 0x0205EB14 | 1;
Player_MoveValueGet = 0x0205EB0C;
Player_DirGet = 0x0205EA78 | 1;
Player_KeyDirGet = 0x02061308 | 1;
PokeParaPut = 0x02074B30 | 1;
CB_Tool_CoreData_Copy = 0x0202CA10 | 1;
sys_FreeMemoryEz = 0x020181C4 | 1;

/*Pokemon*/
PokeParaCalc = 0x0207418C | 1;
PokeLevelCalc = 0x02075B78 | 1;
PokePasoParaPutAct = 0x02074CD8 | 1;
PokeParaFastModeOn = 0x02073C88 | 1;
PokeParaFastModeOff = 0x02073CD4 | 1;
PokePasoParaSet = 0x02073E18 | 1;
PokeParaInit = 0x02073C2C | 1;
PokeParaCoded = 0x0207822C | 1;
PokeFormNoPersonalDataGet = 0x02078208 | 1;
PokeFormNoPersonalParaGet = 0x020759CC | 1;
PokeChrAbiCalc = 0x02075C0C | 1;
PokeSeikakuGet = 0x02075BCC | 1;
PokeParaGet = 0x02074470 | 1;
PokePasoParaGet = 0x02074570 | 1;
PokePasoParaPut = 0x02074C60 | 1;
AusuTypeGet = 0x02077988 | 1;
PokeParaAdrsGet = 0x0207825C | 1;
PokePasoParaSpeabiSet = 0x02078044 | 1;
PokeSexGetMonsNo = 0x02075DAC | 1;
PokeParaCheckSum = 0x0207823C | 1;
PokePasoParaFastModeOn = 0x02073D20 | 1;
PokePasoParaFastModeOff = 0x02073D48 | 1;

/*Mail*/
MailData_CreateWork = 0x0202818C | 1;
MailData_Copy = 0x020281A0 | 1;

/*Item*/
ItemParamGet = 0x0207CFF0 | 1;

/*Waza*/
WT_PPMaxGet = 0x020790DC | 1;

/*Encount stuff*/
ENCEFF_GetEffectNo = 0x021DEEC8 | 1;
/*Message*/
MSGDAT_MonsNameGet = 0x0200B274 | 1;
MSGDAT_UTIL_GetMonsName = 0x0200B32C | 1;
STRBUF_Copy = 0x02023810 | 1; /*might be arm*/
STRBUF_Delete = 0x020237BC | 1; /*might be arm*/
STRBUF_SetStringCode = 0x02023D28 | 1;/*might be arm*/

/*Trainer*/
TT_TrainerDataParaGet = 0x02079220 | 1;
/*CPU func*/
MIi_CpuClearFast = 0x020C4BB8;
memcpy = 0x020D50B8;


Player_DirGet = 0x0205EA78 | 1;
MATR_IsPC = 0x0205DBE4 | 1;
MATR_IsLittleBookRack01 = 0x0205DC80 | 1;
MATR_IsLittleBookRack02 = 0x0205DC8C | 1;
MATR_IsBookRack01 = 0x0205DC98 | 1;
MATR_IsBookRack02 = 0x0205DCA4 | 1;
MATR_IsTrashBox = 0x0205DCB0 | 1;
MATR_IsShopBookRack01 = 0x0205DCBC | 1;
MATR_IsShopBookRack02 = 0x0205DCC8 | 1;
MATR_IsShopBookRack03 = 0x0205DCD4 | 1;
MATR_IsWaterFall = 0x0205DDB4 | 1;
MATR_IsMap = 0x0205DBF0 | 1;
MATR_IsBumpPost = 0x0205DDC0 | 1;
MATR_IsTV = 0x0205DE84 | 1;
Player_EventAttrCheck_KabeNobori = 0x021E0760 | 1;
Player_FormGet = 0x0205EB74 | 1;
SaveData_GetMyStatus = 0x02025E38 | 1;
Player_TwThinkNowAttrGet = 0x02061760 | 1;
Player_EventAttrCheck_Naminori = 0x021E0118 | 1;
MyStatus_GetBadgeFlag = 0x02025F34 | 1;
EvPoke_CheckWaza = 0x020549A0 | 1;
SaveData_GetTemotiPokemon = 0x0207A268 | 1;
MyItem_CheckItem = 0x0207D688 | 1;
SaveData_GetMyItem = 0x0207D990 | 1;
PokeParty_GetMemberPointer = 0x0207A0FC | 1;
BtlTower_IsSalon = 0x0206C0D0 | 1;
PokeList_WazaMenuIDGet = 0x02080BCC | 1;
PokeList_WazaMenuStrGet = 0x02081CAC | 1;
ItemMailCheck = 0x0207D2D0 | 1;
PokeWazaMachineCheck = 0x02077FE4 | 1;
Jiki_KeyDirXGet = 0x02061310 | 1;
Jiki_KeyDirZGet = 0x0206132C | 1;
Player_DirMoveGet = 0x0205EA94 | 1;
Player_InputKeyDirXGet = 0x0205EBE0 | 1;
Player_InputKeyDirZGet = 0x0205EBE8 | 1;
Jiki_MoveNormal = 0x0205FBE4 | 1;
Jiki_MoveCycle = 0x020602DC | 1;
Jiki_MoveCycle4 = 0x0206078C | 1;
Player_FieldOBJGet = 0x0205EB3C | 1;
Player_MoveSpeedAdd = 0x0205EBCC | 1;
Player_MoveHitCheck = 0x02060B7C | 1;
FieldOBJ_DirMoveSet = 0x02062994 | 1;
Snd_SePlay = 0x02005748 | 1;
Player_SaveDataPtrGet = 0x0205EC0C | 1;
Player_SaveDataDashCheck = 0x0205EC40 | 1;
Jiki_MoveNormalAttrAcmdWalkGet = 0x | 1;
FieldOBJ_NowMapAttrGet = 0x0205FC88 | 1;
Jiki_WalkCount = 0x020615C8 | 1;
Player_MoveBitSet_StepON = 0x0205F048 | 1;
FieldOBJ_AcmdCodeDirChange = 0x02065838 | 1;
Jiki_AcmdSet = 0x02060B64 | 1;
Player_MoveSelectValueCheck = 0x02061434 | 1;
Player_MoveValueSet = 0x0205EB08 | 1;
