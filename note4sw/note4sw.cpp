#include <eosiolib/eosio.hpp>

using namespace eosio;

class note4sw : public contract {
public:
    note4sw(account_name s) : contract(s), _notes(s, s) {}

    /// @abi action
    void create( std::string content) {
        //增加数据 ( emplace )
        _notes.emplace(get_self(), [&](auto &n) {
            n.key = _notes.available_primary_key();
            n.id = _notes.available_primary_key();
            n.content = content;
        });
    };

    /// @abi action
    void update(uint64_t id, std::string content) {
        auto itr = _notes.find(id);
        if (itr != _notes.end()) {
            //修改数据 （ modify ）
            _notes.modify(itr, get_self(), [&](auto &n) {
                n.content = content;
            });
        }
    };

    /// @abi action
    void del(uint64_t id) {
        auto itr = _notes.find(id);
        if (itr != _notes.end()) {
            //删除数据 ( erase )
            _notes.erase(itr);
        }
    };

private:

    // create the multi index tables to store the data
    /// @abi table
    struct note {
        uint64_t key; // primary key
        uint64_t id; //  second key
        std::string content;

        uint64_t primary_key() const { return key; }
        uint64_t by_id() const { return id; }
    };

    typedef eosio::multi_index<N(note), note, indexed_by < N(title), const_mem_fun < note, uint64_t, &note::by_id>>> notes;

    // local instances of the multi indexes
    notes _notes;
};

EOSIO_ABI( note4sw, (create)(update)(del))
