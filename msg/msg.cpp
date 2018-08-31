#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
using namespace eosio;

class msg : public eosio::contract {
public:
    using contract::contract;

    /// @abi action
    void hi( account_name to,std::string msg ){
        print( "hi,", name{to},",",msg );
    };
};

EOSIO_ABI( msg, (hi) )