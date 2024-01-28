#include <coreinit/thread.h>
#include <coreinit/time.h>
#include <whb/log.h>
#include <whb/log_console.h>
#include <whb/proc.h>
#include <sysapp/switch.h>
#include <string.h>

#define URL "https://www.google.com/"

int main(int argc, char **argv)
{
    WHBProcInit();
    WHBLogConsoleInit();

    SysAppBrowserArgs args = {0};
    args.url = URL;
    args.urlSize = strlen(URL);

    SYSSwitchToBrowserForViewer(&args);

    WHBLogPrintf("Opening " URL " in browser!");
    WHBLogPrintf("Press HOME to exit.");  
    WHBLogConsoleDraw();
    
    while(WHBProcIsRunning()) {
        WHBLogConsoleDraw();
        OSSleepTicks(OSMillisecondsToTicks(500));
    }

   OSSleepTicks(OSMillisecondsToTicks(500));

   WHBLogConsoleFree();
   WHBProcShutdown();
   return 0;
}
