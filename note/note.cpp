#include <eosiolib/eosio.hpp>
#include <ctime>

using namespace eosio;

class note4sw : public contract {
public:
    note4sw(account_name s) : contract(s), _notes(s, s) {}

    /// @abi action
    void c(std::string poster, std::string title, std::string content, std::string ip,
           std::string summary, std::string tag, char recommend) {
        time_t rawtime;
        _notes.emplace(get_self(), [&](auto &n) {
            n.key = _notes.available_primary_key();
            n.id = _notes.available_primary_key();
            n.poster = poster;
            n.title = title;
            n.poster = poster;
            n.content = content;
            n.ip = ip;
            n.summary = summary;
            n.tag = tag;
            n.recommend = recommend;
            n.postTime = time(&rawtime)*1000;
        });
    };

    /// @abi action
    void u(uint64_t id, std::string title, std::string content, std::string ip,
           std::string summary, std::string tag, char recommend) {
        time_t rawtime;
        auto itr = _notes.find(id);
        if (itr != _notes.end()) {
            _notes.modify(itr, get_self(), [&](auto &n) {
                n.title = title;
                n.content = content;
                n.ip = ip;
                n.summary = summary;
                n.tag = tag;
                n.recommend = recommend;
                n.editTime = time(&rawtime)*1000;
            });
        }
    };

    /// @abi action
    void d(account_name s, uint64_t id) {
        require_auth(s);
        auto itr = _notes.find(id);
        if (itr != _notes.end()) {
            _notes.erase(itr);
        }
    };
private:

    // create the multi index tables to store the data
    /// @abi table
    struct note {
        uint64_t key; // primary key
        uint64_t id; // second key, non-unique, this table will have dup rows for each poll because of option
        std::string poster;
        std::string title;
        std::string content;
        std::string ip;
        std::string summary;
        std::string tag;
        char recommend;
        long postTime;
        long editTime;

        uint64_t primary_key() const { return key; }

        uint64_t by_id() const { return id; }
    };

    typedef eosio::multi_index<N(note), note, indexed_by < N(id), const_mem_fun < note, uint64_t, &note::by_id>>> notes;

    // local instances of the multi indexes
    notes _notes;
};

EOSIO_ABI( note4sw, (c)(u)(d))
