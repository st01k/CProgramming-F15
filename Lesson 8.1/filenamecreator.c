//--------------------------------------------------------------------------------------
//
void printSearchFile ()
{
    char input;

    printf("Would you like to create a data file to search this array (Y/N)? ");
    input = getchar();
    tolower(input);
    switch (input)
    {
        case 'y' :  break;
        case 'n' :  return;
                    break;
        default  :  while (input != 'y' && input != 'n')
                    {
                        printf("\aInvalid Response.  Please re-enter your answer (Y/N): ");
                        scanf(" %c", &input);
                    }
    }

    char file_name[30] = "sorted";
    char bufName[10];
    FILE* out;

    sprintf(bufName, "%d", ARY_SIZE);
    strcat(file_name, bufName);
    strcat(file_name, ".txt");

printf("\n%s\n", file_name);
    out = fopen(file_name, "w");

    fputs("test", out);

    fclose(out);

    return;
}
