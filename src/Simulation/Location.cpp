#include "Location.h"


Location::Location(vertex loc1, VertexObject loc2) {
    sector = loc1;
    local = loc2;
    addSerial(&sector,SSE_SSerializer);
    addSerial(&local,SSE_SSerializer);
}

Location::Location() {
    addSerial(&sector,SSE_SSerializer);
    addSerial(&local,SSE_SSerializer);
}
