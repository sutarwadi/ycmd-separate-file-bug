#include <array>

template <std::size_t dimension, typename F>
class Vector {
public:
  /// Export dimension
  static constexpr std::size_t dim = dimension;
  using Storage = std::array<F, dim>;

  /// Export size_type of the underlying storage
  using size_type = typename std::array<F, dim>::size_type;

  /// Default Constructor
  Vector() = default;

  /// Explicitly Construct from the Field Type
  explicit constexpr Vector(F const& s);

  /// Implicit Conversion Operator only for dimension 1
  template <std::size_t ldim = dim, typename = std::enable_if_t<ldim == 1>>
  constexpr operator F() const;

private:
  Storage x_;
};
template <std::size_t dimension, typename F>
constexpr Vector<dimension, F>::Vector(F const& s)
{
  x_.fill(s);
}

template <std::size_t dim, typename F>
template <std::size_t ldim, typename T>
constexpr Vector<dim, F>::operator F() const
{
  return x_[0];
}
