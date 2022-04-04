
#include "command.h"
#include "client.h"

void Client::Run()
{
    // Txt input 시에 설정. 표준 입력시에 주석 필요
    iStream.SetInputTxt("../AmigoPJT/input_20_20.txt");

    // Txt output 시에 설정. 표준 출력시에 주석 필요
    oStream.SetOutputTxt("../AmigoPJT/output_20_20.txt");

    while (1)
    {
        Command cmd = iStream.Input();

        if (!cmd.IsValid())
        {
            break;
        }

        string result;
        
        // cmd.cmd_type은 enum에 맞게 변경 필요.
        result = Commands[cmd.cmd_type]->Process(cmd);

        oStream.Output(result);
    }

    // sample 정답지와 amigo 답안지와 비교하여 pass / fail 확인 필요.
}