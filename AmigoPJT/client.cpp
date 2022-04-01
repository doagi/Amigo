
#include "command.h"
#include "client.h"

void Client::Run()
{
    // Txt input 시에 설정. 표준 입력시에 주석 필요
    iStream.SetInputTxt("../AmigoPJT/input_20_20.txt");    

    while (1)
    {
        Command cmd = iStream.Input();

        if (!cmd.IsValid())
        {
            break;
        }
    }
}