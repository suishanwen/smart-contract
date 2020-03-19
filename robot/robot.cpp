#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <eosio/transaction.hpp>
#include <eosio/crypto.hpp>
using namespace eosio;

class [[eosio::contract("robot")]] robot : public eosio::contract {
public:
    robot(name receiver, name code,  datastream<const char*> ds): contract(receiver, code, ds) {}

    [[eosio::action]]
    void receive(name from,name to,asset quantity,uint64_t thread) {
        check(from != to, "cannot transfer to self");
        check(is_account(to), "to account does not exist");
        check(quantity.is_valid(), "invalid quantity");
        check(quantity.amount > 0, "must transfer positive quantity");
        require_auth(from);
        require_recipient(from);
        require_recipient(to);
        tip_index tips( get_self(), get_first_receiver().value );
        tips.emplace(from, [&]( auto& row ) {
          row.key = tips.available_primary_key();
          row.thread = thread;
          row.from = from;
          row.quantity = quantity;
          row.trxid = get_trx_id();
        });
    }

    [[eosio::action]]
     void erase(name user) {
       require_auth(user);
       tip_index tips( get_self(), get_first_receiver().value );
       auto iterator = tips.find(user.value);
       check(iterator != tips.end(), "Record does not exist");
       tips.erase(iterator);
     }

    checksum256 get_trx_id() {
        size_t size = transaction_size();
        char buf[size];
        size_t read = read_transaction( buf, size );
        check( size == read, "read_transaction failed");
        return sha256( buf, read );
    }

private:
    struct [[eosio::table]] tip {
        uint64_t key;
        uint64_t thread;
        name from;
        asset quantity;
        checksum256 trxid;

        uint64_t primary_key() const { return key; }
        uint64_t find_by_thread() const { return thread; }
        uint64_t find_by_name() const { return from.value;}

    };
    typedef eosio::multi_index<"tip"_n, tip,
    indexed_by<"bythread"_n, const_mem_fun<tip, uint64_t, &tip::find_by_thread>>,
    indexed_by<"bytname"_n, const_mem_fun<tip, uint64_t, &tip::find_by_name>>> tip_index;

};
