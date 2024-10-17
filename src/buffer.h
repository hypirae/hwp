#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <stdlib.h>
#include <string.h>

/**
 * hwpbuffer: A simple buffer structure.
 * 
 * @data The data in the buffer.
 * @size The size of the data in the buffer.
 * @capacity The capacity of the buffer.
 * 
 * @note: the buffer is a simple dynamic array.
 */
typedef struct hwp_buffer
{
  char *data;
  size_t size;
  size_t capacity;
} HWPBUFFER;

// forward declarations
HWPBUFFER *hwpbuffer_alloc (size_t capacity);
void hwpbuffer_dealloc (HWPBUFFER *buffer);
HWPBUFFER *hwpbuffer_append (HWPBUFFER *buffer, const char *data, size_t size);
HWPBUFFER *hwpbuffer_prepend (HWPBUFFER *buffer, const char *data, size_t size);
char *hwpbuffer_slice (HWPBUFFER *buffer, size_t start, size_t end);

/**
 * hwpbuffer_alloc: Allocate a new buffer with the given capacity.
 * 
 * @param capacity The initial capacity of the buffer.
 * 
 * @return A pointer to the newly allocated buffer.
 * 
 * @note: the allocated buffer will be zeroed out.
 */
HWPBUFFER *
hwpbuffer_alloc (size_t capacity)
{
  HWPBUFFER *buffer = malloc (sizeof (HWPBUFFER));

  // always zero out the memory
  buffer->data = calloc (capacity, sizeof (char));
  buffer->size = 0;
  buffer->capacity = capacity;

  return buffer;
}

/**
 * hwpbuffer_dealloc: Deallocate the given buffer.
 * 
 * @param buffer The buffer to deallocate.
 */
void
hwpbuffer_dealloc (HWPBUFFER *buffer)
{
  if (buffer)
    {
      if (buffer->data)
        {
          free (buffer->data);
        }

      free (buffer);
    }
}

/**
 * hwpbuffer_append: Append the given data to the buffer.
 * 
 * @param buffer The buffer to append to.
 * @param data The data to append.
 * @param size The size of the data to append.
 * 
 * @return The buffer.
 */
HWPBUFFER *
hwpbuffer_append (HWPBUFFER *buffer, const char *data, size_t size)
{
  if (buffer->size + size > buffer->capacity)
    {
      size_t new_capacity = buffer->capacity * 2;
      char *new_data = realloc (buffer->data, new_capacity);

      if (new_data)
        {
          buffer->data = new_data;
          buffer->capacity = new_capacity;
        }
      else
        {
          return buffer;
        }
    }

  memcpy (buffer->data + buffer->size, data, size);
  buffer->size += size;

  return buffer;
}

/**
 * hwpbuffer_prepend: Prepend the given data to the buffer.
 * 
 * @param buffer The buffer to prepend to.
 * @param data The data to prepend.
 * @param size The size of the data to prepend.
 * 
 * @return The buffer.
 */
HWPBUFFER *
hwpbuffer_prepend (HWPBUFFER *buffer, const char *data, size_t size)
{
  if (buffer->size + size > buffer->capacity)
    {
      size_t new_capacity = buffer->capacity * 2;
      char *new_data = realloc (buffer->data, new_capacity);

      if (new_data)
        {
          buffer->data = new_data;
          buffer->capacity = new_capacity;
        }
      else
        {
          return buffer;
        }
    }

  memmove (buffer->data + size, buffer->data, buffer->size);
  memcpy (buffer->data, data, size);
  buffer->size += size;

  return buffer;
}

/**
 * hwpbuffer_slice: Return a slice of the buffer.
 * 
 * @param buffer The buffer to slice.
 * @param start The start index of the slice.
 * @param end The end index of the slice.
 * 
 * @return The slice of the buffer.
 * 
 * @note: caller must free the returned slice.
 */
char *
hwpbuffer_slice (HWPBUFFER *buffer, size_t start, size_t end)
{
  if (start >= buffer->size || end > buffer->size || start >= end)
    {
      return NULL;
    }

  size_t size = end - start;
  char *slice = calloc (size + 1, sizeof(char));

  memcpy (slice, buffer->data + start, size);

  return slice;
}

#endif