variable [a-zA-z_]{1}[a-zA-Z0-9_]*
integer \-?[0]{1}|(\-?)[1-9]{1}[0-9]*
decimal (\-?)((0?\.[0-9]*[1-9][0-9]*)|(([1-9]{1}[0-9]*)((\.([0-9]*[1-9][0-9]*))|(\.0)))|(0\.0){1})
pow [p|P][o|O][w|W]\(({integer}|{decimal}),({integer}|{decimal})\)
pow1 ({decimal}|{integer})\^({decimal}|{integer})
mod mod\(({integer}|{decimal}),({integer}|{decimal})\)
%%
{variable} {printf("variable ");}
{integer} {printf("integer_number ");}
{decimal} {printf("decimal_number ");}
{pow} {printf("potency ");}
{pow1} {printf("potency ");}
{mod} {printf("module ");}
\= {printf("equal ");}
\+ {printf("sum ");}
\- {printf("minus ");}
\* {printf("multiply ");}
\/ {printf("divition ");}
