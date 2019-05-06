#include <map>
#include <search.hpp>  

typedef std::map<int, int> UsersMap; // several typedefs should be fixed


template <>
Search<UsersMap>::Search() {}

template <>
void Search<UsersMap>::AcceptRequest() {}

template <>
void Search<UsersMap>::RunSearch() {
    for (auto request: request_vector_) {
        int state = request->GetState();
        switch(state) {
            case request_state::READY_FOR_CLIENT:
                continue;
            case request_state::READY_TO_PROCESS:
                request->Calculate();
                continue;
            case request_state::OVER:
                continue;
            case request_state::WAITING:
                continue;
        }
    }
}
