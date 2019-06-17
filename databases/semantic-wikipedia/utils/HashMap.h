// Copyright 2011, University of Freiburg, Chair of Algorithms and Data
// Structures.
// Author: Björn Buchhold <buchholb>

#ifndef SEMANTIC_WIKIPEDIA_UTILS_HASHMAP_H_
#define SEMANTIC_WIKIPEDIA_UTILS_HASHMAP_H_

#include <google/dense_hash_map>

#include "./DefaultKeyProvider.h"

namespace ad_utility
{
//! Wrapper for HashMaps to be used everywhere throughout code for
//! the semantic search. This wrapper interface is not designed to
//! be complete from the beginning. Feel free to extend it at need.
//! The first version as of May 2011 uses google's dense_hash_map.
//! Backing-up implementations may be changed in the future.
template<class K, class V>
class HashMap
{
  public:
    HashMap<K, V> () :
      _impl()
    {
      _impl.set_empty_key(DefaultKeyProvider<K>::DEFAULT_EMPTY_KEY);
      _impl.set_deleted_key(DefaultKeyProvider<K>::DEFAULT_DELETED_KEY);
    }


    typedef typename google::dense_hash_map<K, V>::iterator iterator;
    typedef typename google::dense_hash_map<K, V>::const_iterator
        const_iterator;

    void set_empty_key(const K& emptyKey)
    {
      _impl.set_empty_key(emptyKey);
    }

    void set_deleted_key(const K& emptyKey)
    {
      _impl.set_deleted_key(emptyKey);
    }

    const_iterator begin() const
    {
      return _impl.begin();
    }

    const_iterator end() const
    {
      return _impl.end();
    }

    iterator begin()
    {
      return _impl.begin();
    }

    iterator end()
    {
      return _impl.end();
    }

    iterator find(const K& key)
    {
      return _impl.find(key);
    }
    const_iterator find(const K& key) const
    {
      return _impl.find(key);
    }

    //! Lookup operator that also adds pairs whenever
    //! they don't exist, using @param key as key
    //! and a value /w default constructor.
    //! If this is not the behavior you want, use "find" instead.
    V& operator[](const K& key)
    {
      return _impl[key];
    }

    size_t count(const K& key) const
    {
      return _impl.count(key);
    }

    size_t size() const
    {
      return _impl.size();
    }

    void clear()
    {
      _impl.clear();
    }

  private:
    google::dense_hash_map<K, V> _impl;
};
}

#endif  // SEMANTIC_WIKIPEDIA_UTILS_HASHMAP_H_
