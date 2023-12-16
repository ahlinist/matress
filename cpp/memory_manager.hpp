#pragma once

namespace memory {
    class MemoryManager {
    public:
        virtual ~MemoryManager() {}
        virtual void cleanup_matrix(long double** matrix, const int &size) = 0;
    };

    class MemoryManagerImpl : public MemoryManager {
    public:
        void cleanup_matrix(long double** matrix, const int &size) override;
    };
}
