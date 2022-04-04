
#include "command.h"
#include "client.h"


void Client::Run()
{
    // Txt input 시에 설정. 표준 입력시에 주석 필요
    iStream.SetInputTxt("../AmigoPJT/input_20_20.txt");

    // Txt output 시에 설정. 표준 출력시에 주석 필요
    oStream.SetOutputTxt("../AmigoPJT/output_20_20.txt");

    //map<string, int> supported_cmds_amigo_db = amigo_db->GetSupportedCmds();

    while (1)
    {
        Command cmd = iStream.Input();

        if (!cmd.IsValid())
        {
            break;
        }

#if 0
        int cmd_handler_index = supported_cmds_amigo_db[cmd.GetCommandType()];

        if (CommandType_count <= cmd_handler_index)
        {
            // exception
            break;
        }

        string result = cmd_handlers[cmd_handler_index]->Process(cmd);
#endif
        string result = amigo_db->Query(cmd);

        if (result.length() > 1)
        {
            oStream.Output(result);
        }
    }
}