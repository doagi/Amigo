
#include "command.h"
#include "client.h"


void Client::Run()
{
    // Txt input 시에 설정. 표준 입력시에 주석 필요
    iStream.SetInputTxt("../AmigoPJT/input_20_20.txt");

    // Txt output 시에 설정. 표준 출력시에 주석 필요
    oStream.SetOutputTxt("../AmigoPJT/amigo_output_20_20.txt");

    map<string, int> supported_cmds_amigo_db = amigo_db->GetSupportedCmds();

    while (1)
    {
        Command cmd = iStream.Input();

        if (!cmd.IsValid())
        {
            break;
        }

        int cmd_handler_index = supported_cmds_amigo_db[cmd.param[Command::cmd_type]];

        string result = cmd_handlers[cmd_handler_index]->Process(cmd);

        oStream.Output(result);
    }

    // sample 정답지와 amigo 답안지와 비교하여 pass / fail 확인 필요.
}