#include <cstdlib>
#include <type_traits>
template <typename VectorType>
class Vector {
  size_t m_Capacity = 200;
  size_t m_Size = 0;
  VectorType* m_Data = static_cast<VectorType*>(
          ::operator new(m_Capacity *
              sizeof(VectorType)));


  void Realloc(size_t new_Capacity) {
    if (new_Capacity > m_Capacity) {
      m_Capacity = new_Capacity;
      VectorType* temp = static_cast<VectorType*>(
          ::operator new(new_Capacity * sizeof(VectorType)));

      for (size_t i = 0; i < m_Size; ++i) {
        temp[i] = std::move(m_Data[i]);
      }

      ::operator delete(m_Data);
      m_Data = temp;
    }
  }
  void _shift_to_left() {
    for (size_t i = 0; i < m_Capacity; ++i) {
      m_Data[i] = std::move(m_Data[i + 1]);
    }
  }
  void _shift_to_right() {
    for (size_t i = m_Capacity; i > 0; --i) {
      m_Data[i] = std::move(m_Data[i - 1]);
    }
  }
  void _shift_to_left_from(size_t index) {
    for (size_t i = index; i < m_Capacity; ++i) {
      m_Data[i] = std::move(m_Data[i + 1]);
    }
  }
  void _shift_to_right_from(size_t index) {
    for (size_t i = m_Capacity; i > index; --i) {
      m_Data[i] = std::move(m_Data[i - 1]);
    }
  }

 public:
  constexpr Vector() {}
  template <size_t N>
  explicit Vector(const VectorType (&arr)[N]) {
    if (N >= m_Capacity) {
      Realloc(m_Capacity * 1.5);
    }
    for (size_t i = 0; i < N - 1; ++i) {
      pushBack(arr[i]);
    }
  }
  template <size_t N>
  explicit Vector(const VectorType(&&arr)[N]) {
    if (N >= m_Capacity) {
      Realloc(m_Capacity * 1.5);
    }
    for (size_t i = 0; i < N - 1; ++i) {
      pushBack(std::move(arr[i]));
    }
  }
  Vector(const Vector<VectorType>& vec) { m_Data = (vec.data()); }
  Vector(Vector<VectorType>&& vec) { m_Data = std::move(vec.data()); }
  ~Vector() requires(std::is_destructible<VectorType>::value) {
    Clear();
    ::operator delete(m_Data);
  }
  ~Vector() = default;

  void pushBack(const VectorType& element) {
    if (m_Size >= m_Capacity) Realloc(m_Capacity * 1.5);
    m_Data[m_Size] = element;
    m_Size++;
  }
  void pushBack(VectorType&& element) {
    if (m_Size >= m_Capacity) Realloc(m_Capacity * 1.5);
    m_Data[m_Size] = std::move(element);
    m_Size++;
  }
  void popBack() {
    if (m_Size > 0) {
      m_Size--;
      m_Data[m_Size].~VectorType();
    }
  }
  void pushFront(const VectorType& element) {
    if (m_Size >= m_Capacity) Realloc(m_Capacity * 1.5);
    _shift_to_right();
    m_Data[0] = element;
    m_Size++;
  }
  void pushFront(VectorType&& element) {
    if (m_Size >= m_Capacity) Realloc(m_Capacity * 1.5);
    _shift_to_right();
    m_Data[0] = std::move(element);
    m_Size++;
  }
  void popFront() {
    if (m_Size > 0) {
      m_Size--;
      m_Data[0].~VectorType();
      _shift_to_left_from(0);
    }
  }
  void Resize(size_t _newSize) {
    if (_newSize >= m_Capacity && _newSize != m_Size) {
      Realloc(m_Capacity * 1.5);
      m_Size = _newSize;
    } else if (_newSize < m_Capacity && _newSize != m_Size) {
      m_Size = _newSize;
    }
  }

  // getters
  VectorType* getData() const { return m_Data; }
  bool isEmpty() const { return (m_Size == 0); }
  size_t Size() const { return m_Size; }
  size_t Capacity() const { return m_Capacity; }
  auto begin() const { return &(m_Data[0]); }
  auto end() const { return &(m_Data[m_Size]); }
  void Clear() {
    for (size_t index = 0; index < m_Size; ++index) {
      m_Data[index].~VectorType();
    }
    m_Size = 0;
  }

  // operators
  VectorType& operator[](size_t index) { return (m_Data[index]); }
};
