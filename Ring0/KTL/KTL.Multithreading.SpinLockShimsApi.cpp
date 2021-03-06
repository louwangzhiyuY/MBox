#include "KTL.Multithreading.SpinLockShimsApi.h"

namespace ktl
{
    inline namespace multithreading
    {

#pragma prefast(push)
#pragma prefast(disable:28167 28122, "I known.")
        namespace ShimsApi
        {
            KIRQL __stdcall ExAcquireSpinLockExclusiveShims(PEX_SPIN_LOCK aExSpinLock)
            {
                using ExAcquireSpinLockExclusive$Fun = KIRQL(__stdcall*)(PEX_SPIN_LOCK);
                static ExAcquireSpinLockExclusive$Fun sExAcquireSpinLockExclusive = nullptr;

                if (nullptr == sExAcquireSpinLockExclusive)
                {
                    UNICODE_STRING vRoutineName = RTL_CONSTANT_STRING(L"ExAcquireSpinLockExclusive");
                    auto vRoutine = MmGetSystemRoutineAddress(&vRoutineName); 
                    sExAcquireSpinLockExclusive = (ExAcquireSpinLockExclusive$Fun)vRoutine;
                }

                if (sExAcquireSpinLockExclusive)
                {
                    return sExAcquireSpinLockExclusive(aExSpinLock);
                }

                KIRQL vIrql = 0;
                KeAcquireSpinLock((PKSPIN_LOCK)aExSpinLock, &vIrql);
                return vIrql;
            }

            void __stdcall ExReleaseSpinLockExclusiveShims(PEX_SPIN_LOCK aExSpinLock, KIRQL aIrql)
            {
                using ExReleaseSpinLockExclusive$Fun = void(__stdcall*)(PEX_SPIN_LOCK, KIRQL);
                static ExReleaseSpinLockExclusive$Fun sExReleaseSpinLockExclusive = nullptr;

                if (nullptr == sExReleaseSpinLockExclusive)
                {
                    UNICODE_STRING vRoutineName = RTL_CONSTANT_STRING(L"ExReleaseSpinLockExclusive");
                    auto vRoutine = MmGetSystemRoutineAddress(&vRoutineName);
                    sExReleaseSpinLockExclusive = (ExReleaseSpinLockExclusive$Fun)vRoutine;
                }

                if (sExReleaseSpinLockExclusive)
                {
                    return sExReleaseSpinLockExclusive(aExSpinLock, aIrql);
                }

                KeReleaseSpinLock((PKSPIN_LOCK)aExSpinLock, aIrql);
            }

            KIRQL __stdcall ExAcquireSpinLockSharedShims(PEX_SPIN_LOCK aExSpinLock)
            {
                using ExAcquireSpinLockShared$Fun = KIRQL(__stdcall*)(PEX_SPIN_LOCK);
                static ExAcquireSpinLockShared$Fun sExAcquireSpinLockShared = nullptr;

                if (nullptr == sExAcquireSpinLockShared)
                {
                    UNICODE_STRING vRoutineName = RTL_CONSTANT_STRING(L"ExAcquireSpinLockShared");
                    auto vRoutine = MmGetSystemRoutineAddress(&vRoutineName);
                    sExAcquireSpinLockShared = (ExAcquireSpinLockShared$Fun)vRoutine;
                }

                if (sExAcquireSpinLockShared)
                {
                    return sExAcquireSpinLockShared(aExSpinLock);
                }

                KIRQL vIrql = 0;
                KeAcquireSpinLock((PKSPIN_LOCK)aExSpinLock, &vIrql);
                return vIrql;
            }

            void __stdcall ExReleaseSpinLockSharedShims(PEX_SPIN_LOCK aExSpinLock, KIRQL aIrql)
            {
                using ExReleaseSpinLockShared$Fun = void(__stdcall*)(PEX_SPIN_LOCK, KIRQL);
                static ExReleaseSpinLockShared$Fun sExReleaseSpinLockShared = nullptr;

                if (nullptr == sExReleaseSpinLockShared)
                {
                    UNICODE_STRING vRoutineName = RTL_CONSTANT_STRING(L"ExReleaseSpinLockShared");
                    auto vRoutine = MmGetSystemRoutineAddress(&vRoutineName);
                    sExReleaseSpinLockShared = (ExReleaseSpinLockShared$Fun)vRoutine;
                }

                if (sExReleaseSpinLockShared)
                {
                    return sExReleaseSpinLockShared(aExSpinLock, aIrql);
                }

                KeReleaseSpinLock((PKSPIN_LOCK)aExSpinLock, aIrql);
            }

            unsigned long __stdcall ExTryConvertSharedSpinLockExclusiveShims(PEX_SPIN_LOCK aExSpinLock)
            {
                using ExTryConvertSharedSpinLockExclusive$Fun = unsigned long(__stdcall*)(PEX_SPIN_LOCK);
                static ExTryConvertSharedSpinLockExclusive$Fun sExTryConvertSharedSpinLockExclusive = nullptr;

                if (nullptr == sExTryConvertSharedSpinLockExclusive)
                {
                    UNICODE_STRING vRoutineName = RTL_CONSTANT_STRING(L"ExTryConvertSharedSpinLockExclusive");
                    auto vRoutine = MmGetSystemRoutineAddress(&vRoutineName);
                    sExTryConvertSharedSpinLockExclusive = (ExTryConvertSharedSpinLockExclusive$Fun)vRoutine;
                }

                if (sExTryConvertSharedSpinLockExclusive)
                {
                    return sExTryConvertSharedSpinLockExclusive(aExSpinLock);
                }

                return false;
            }

        }
#pragma prefast(pop)

    }
}
