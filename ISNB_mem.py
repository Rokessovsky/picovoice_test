from collections import OrderedDict


def get_book_info_with_cache(isbn, cache_size):
    if isbn in get_book_info_with_cache.cache:
        # If the result is already in the cache, return it
        return get_book_info_with_cache.cache[isbn]
    else:
        # Otherwise, call the original function to retrieve the result
        result = get_book_info(isbn)
        # Store the result in the cache
        get_book_info_with_cache.cache[isbn] = result
        # If the cache has reached its maximum size, remove the earliest added item
        if len(get_book_info_with_cache.cache) > cache_size:
            # (k := next(iter(get_book_info_with_cache.cache)), get_book_info_with_cache.cache.pop(k))
            get_book_info_with_cache.cache.popitem(last=False)
        return result


# Initialize the cache as an ordered dictionary with a maximum size of N
get_book_info_with_cache.cache = OrderedDict()
