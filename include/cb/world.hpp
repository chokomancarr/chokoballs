#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

class World {
    std::vector<Object> objects;

public:
    pWorld Create();
};

CB_END_NAMESPACE