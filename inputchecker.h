string get_input()
{
        int err_flag;
        string input_string;
        do
        {
                cin>>input_string;
                err_flag=0;
                for(int i=0; i<strlen(input_string.c_str()); i++)
                        if(input_string[i]<48 || input_string[i]>57)		//ASCII values of 0 to 9 : 48 to 57.
                        {
                                err_flag=1;					//err_flag is set if the character is not a digit.
                                break;
                        }
                if(err_flag==1)
                        cout<<"Enter a valid input, please.\n";
        }while(err_flag==1);
        return input_string;
}

