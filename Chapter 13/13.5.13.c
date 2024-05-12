#include <stdio.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url);

int main(void)
{
    char domain[] = "knking.com";
    char index_url[100];

    build_index_url(domain, index_url);

    printf("%s", index_url);

    return 0;
}

void build_index_url(const char *domain, char *index_url)
{
    strcpy(index_url, "http://www.");
    strcat(strcat(index_url, domain), "/index.html");
}