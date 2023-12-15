#pragma once

namespace memory {
    class MemoryManager {
    public:
        virtual ~MemoryManager() {}
        virtual void cleanup_matrix(double** matrix, int size) = 0;
    };

    class MemoryManagerImpl : public MemoryManager {
    public:
        void cleanup_matrix(double** matrix, int size) override;
    };
}