#include <iostream>

#include "command.h"
#include "client.h"

Client::Client()
{
    amigo_db = new AmigoDatabase();

    map<string, int> supported_cmds_amigo_db = amigo_db->GetSupportedCmds();

    for (auto value : supported_cmds_amigo_db)
    {
        switch (value.second)
        {
        case AddCommand:
            cmd_handlers[value.second] = new AddCommandHandler();
            cmd_handlers[value.second]->SetDatabase(amigo_db);
            break;
        case DelCommand:
            cmd_handlers[value.second] = new DelCommandHandler();
            cmd_handlers[value.second]->SetDatabase(amigo_db);
            break;
        case ModCommand:
            cmd_handlers[value.second] = new ModCommandHandler();
            cmd_handlers[value.second]->SetDatabase(amigo_db);
            break;
        case SchCommand:
            cmd_handlers[value.second] = new SchCommandHandler();
            cmd_handlers[value.second]->SetDatabase(amigo_db);
            break;
        default:
            break;
        }
    }
}

Client::Client(const string& input_path_, const string& output_path_) : Client()
{
    input_path = input_path_;
    output_path = output_path_;
}

void Client::Run(const bool& debug_print)
{
    Run(input_path, output_path, debug_print);
}

void Client::Run(const string& input_path_, const string& output_path_, const bool& debug_print) try
{
    if (input_path_.empty() || output_path_.empty())
    {
        throw invalid_argument("Input or Output path is empty");
    }

    InputStream input_stream{ input_path_ };
    OutputStream output_stream{ output_path_ };

    //map<string, int> supported_cmds_amigo_db = amigo_db->GetSupportedCmds();

    while (1)
    {
        Command cmd = input_stream.Input();

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
            output_stream.Output(result);

            if (debug_print)
            {
                cout << result << endl;
            }
        }
    }
}
catch (const exception& ex)
{
    cout << endl << "ERROR: " << ex.what() << endl;
}