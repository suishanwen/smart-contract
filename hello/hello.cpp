#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
using namespace eosio;

class hello : public eosio::contract {
public:
    using contract::contract;

    /// @abi action
    void hi( account_name to ) {
        print( "Hello, ", name{to} );
    }
};

EOSIO_ABI( hello, (hi) )