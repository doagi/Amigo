#include <iostream>

#include "client.h"

Client::Client()
{
    amigo_db = new AmigoDatabase();
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

    while (1)
    {
        Command cmd = input_stream.Input();

        if (!cmd.IsValid())
        {
            break;
        }

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