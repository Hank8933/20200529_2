#include <stdio.h>
#include <stdlib.h>

const struct {
    char *country;
    int code;
} country_codes[] =
    {{"Argentina",            54}, {"Bangladesh",     889},
     {"Brazil",               55}, {"Burma (Myanmar)", 95},
     {"China",                86}, {"Colombia",        57},
     {"Congo, Dem. Rep. of", 243}, {"Egypt",           20},
     {"Ethiopia",            251}, {"France",          33},
     {"Germany",              49}, {"India",           91},
     {"Indonesia",            62}, {"Iran",            98},
     {"Italy",                39}, {"Japan",           81},
     {"Mexico",               52}, {"Nigeria",        234},
     {"Pakistan",             92}, {"Philippines",     63},
     {"Poland",               48}, {"Russia",           7},
     {"South Africa",         27}, {"South Korea",     82},
     {"Spain",                34}, {"Sudan",          249},
     {"Thailand",             66}, {"Turkey",          90},
     {"Ukraine",             380}, {"United Kingdom",  44},
     {"United States",         1}, {"Vietnam",         84}};

#define ccs country_codes
void findcode()
{
    int n;
    scanf("%d", &n);
    int size = (sizeof(ccs) / sizeof(*ccs));
    for(int i = 0; i < size; i++){
        if(ccs[i].code == n){
            printf("%s", ccs[i].country);
            return;
        }
    }
    printf("error: not find");
}

int main()
{
    findcode();
    return 0;
}
