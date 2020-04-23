#include <comunication.hpp>
int main(int argc, char const *argv[])
{
    if (strncmp (SERVER, argv[1], strlen (SERVER)) == 0 && argc > 1)
    {
        return server (argv[2]);
    }
    else if (strncmp (CLIENT, argv[1], strlen (CLIENT)) == 0 && argc > 1)
    {

        return client (argv[2]);
    }
    else
    {
        fprintf (stderr, "Usage: reqrep %s|%s <URL> <ARG> ...\n",
                SERVER, CLIENT);
        return 1;
    }
    return 0;
}
