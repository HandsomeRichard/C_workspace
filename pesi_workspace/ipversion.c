#include <arpa/inet.h>
#include <stdio.h>

static int ip_version(const char *src);

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        printf("%s\t%d\n", argv[i], ip_version(argv[i]));
    }

    return 0;
}

static int ip_version(const char *src)
{
    char buf[16];
    if (inet_pton(AF_INET, src, buf))
    {
        return 4;
    }
    else if (inet_pton(AF_INET6, src, buf))
    {
        return 6;
    }
    return -1;
}

int checkIPParam(IP_Param *IPParam)
{
    int ErrorNo = 0;

    pesi_log_console("----CHECK ALL NOT NULL-----");
    if (IPParam->ip_enable == NULL && IPParam->client_ip == NULL)
    {
        CGI_XML_VALUE("Error", "IP Parameters are NULL!");
        return -1;
    }

    pesi_log_console("----CHECK CHECKITEM_IP_ENABLE-----");
    ErrorNo = pesi_check_param(CHECKTYPE_SNMP, IPParam->ip_enable, CHECKITEM_IP_ENABLE);
    if (ErrorNo < 0)
    {
        CGI_XML_VALUE("Error", "%s", "IP enable value error.");
        return ErrorNo;
    }

    pesi_log_console("----CHECK CHECKITEM_CLIENT_IP-----");
    ErrorNo = pesi_check_param(CHECKTYPE_SNMP, IPParam->client_ip, CHECKITEM_CLIENT_IP);

    if (ErrorNo < 0)
    {

        switch (ErrorNo)
        {
        case -1:
            CGI_XML_VALUE("Error", "%s", "Client IP value is NULL.");
            break;

        case -2:
            CGI_XML_VALUE("Error", "%s", "Client IPv4 value error.");
            break;

        case -3:
            CGI_XML_VALUE("Error", "%s", "Client IPv6 value error.");
            break;

        case -4:
            CGI_XML_VALUE("Error", "%s", "Invalid IP address!");
            break;
        }

        return ErrorNo;
    }

    return ErrorNo;
}