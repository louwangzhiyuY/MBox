#pragma once

namespace MBox
{
    namespace Vol
    {
        namespace DateTime
        {
            enum : UINT32
            {
                Infinite = 0xFFFFFFFF,
            };

            PLARGE_INTEGER FormatTimeoutToLargeInteger(
                PLARGE_INTEGER aTimeout,
                UINT32 aMilliseconds);

            void GetLocalTime(PLARGE_INTEGER aLocalTime);

            void GetLocalTimeFields(PTIME_FIELDS aTimeFields);
        }
    }
}
