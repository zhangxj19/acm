#ifndef Stream_hpp
#define Stream_hpp

#include <vector>
#include <functional>
#include <iostream>
#include <numeric>
#include <map>

template<typename T>
class Stream 
{
public:

    Stream(const std::vector<T>& original_data)
        : data(original_data)
    {
    }

    static Stream<T> make_stream(const std::vector<T>& container);
    
    // map_func input T output M
    template<typename M>
    Stream<M> map(std::function<M(const T &)> map_func) const
    {
        std::vector<M> tmp;
        for(auto &d : data)
        {
            tmp.emplace_back(map_func(d));
        }
        return Stream<M>(tmp);
    }
    
    Stream<T> filter(std::function<bool(const T &)> filter_func) const
    {
        std::vector<T> tmp;
        for(auto &d : data)
        {
            if(filter_func(d)) tmp.emplace_back(d);
        }
        return Stream<T>(tmp);
    }    

    template<typename K, typename V>
    std::map<K, Stream<V>> group_by_key(std::function<K(const T&)> get_key, std::function<V(const T&)> get_value) const
    {
        std::map<K, std::vector<V>> res;
        std::map<K, Stream<V>> res_map;
        for(auto &d : data)
        {
            auto iter = res.find(get_key(d));
            if(iter == res.end()) iter = res.emplace_hint(iter, std::make_pair(get_key(d), std::vector<V>()));
            iter->second.emplace_back(get_value(d));
        }
        for(auto &v: res)
        {
            res_map.emplace(v.first, Stream<V>(v.second));
        }
        return res_map;
    }    

    T reduce(T init, std::function<T(const T&, const T&)> combination_func) const
    {
        for(auto &d : data)
        {
            init = combination_func(init, d);
        }
        return init;
    }    

    std::vector<T> collect() const
    {
        return data;
    }
    
private:
    // you can add or delete anything you want in private field
    const std::vector<T> data;
};

#endif /* Stream_hpp */
