using namespace std;

int main(int argc, char** argv)
{
    string input_path;
    string output_path;

    if (argc == 3)
    {
        input_path = argv[1];
        output_path = argv[2];
    }
    else
    {
        cout << "[Debugging] Set default file path" << endl;
        input_path = "../AmigoPJT/input_20_20.txt";
        output_path = "../AmigoPJT/output_20_20.txt";
        cout << "- Input  : " << input_path << endl;
        cout << "- Output : " << output_path << endl << endl;
    }

    Client amigo_client{ input_path, output_path };
    amigo_client.Run(true);

#if _DEBUG
    if (argc != 3)
    {
        Compare("output_20_20_ref.txt", output_path);
    }
#endif

    return 0;
}