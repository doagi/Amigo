
#include "command.h"
#include "client.h"

void Client::Run()
{
    // Txt input �ÿ� ����. ǥ�� �Է½ÿ� �ּ� �ʿ�
    iStream.SetInputTxt("../AmigoPJT/input_20_20.txt");

    // Txt output �ÿ� ����. ǥ�� ��½ÿ� �ּ� �ʿ�
    oStream.SetOutputTxt("../AmigoPJT/output_20_20.txt");

    while (1)
    {
        Command cmd = iStream.Input();

        if (!cmd.IsValid())
        {
            break;
        }

        string result;
        
        // cmd.cmd_type�� enum�� �°� ���� �ʿ�.
        result = Commands[cmd.cmd_type]->Process(cmd);

        oStream.Output(result);
    }

    // sample �������� amigo ������� ���Ͽ� pass / fail Ȯ�� �ʿ�.
}