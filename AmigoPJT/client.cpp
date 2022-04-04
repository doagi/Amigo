
#include "command.h"
#include "client.h"


void Client::Run()
{
    // Txt input �ÿ� ����. ǥ�� �Է½ÿ� �ּ� �ʿ�
    iStream.SetInputTxt("../AmigoPJT/input_20_20.txt");

    // Txt output �ÿ� ����. ǥ�� ��½ÿ� �ּ� �ʿ�
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

    // sample �������� amigo ������� ���Ͽ� pass / fail Ȯ�� �ʿ�.
}