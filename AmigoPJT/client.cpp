
#include "command.h"
#include "client.h"

void Client::Run()
{
    // Txt input �ÿ� ����. ǥ�� �Է½ÿ� �ּ� �ʿ�
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