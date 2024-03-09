#ifndef CONJUGATE_HPP__
#define CONJUGATE_HPP__

#include <array>
#include <cmath>
#include <cstdint>
#include <type_traits>

namespace conjugate {
    template <typename T, std::size_t N>
    class Vector {
        static_assert(std::is_floating_point<T>::value);

        typedef T 	    			                    value_type;
        typedef value_type *			                pointer;
        typedef const value_type *                      const_pointer;
        typedef value_type&                   	        reference;
        typedef const value_type&             	        const_reference;
        typedef value_type*          		            iterator;
        typedef const value_type*			            const_iterator;
        typedef std::size_t                    	        size_type;
        typedef std::ptrdiff_t                   	    difference_type;
        typedef std::reverse_iterator<iterator>	        reverse_iterator;
        typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;

        public:
            Vector() {}
            Vector(const std::array<T, N>& xs) : value_(xs) {}
            Vector(T x) : value_({x}) {}

            reference
            operator[](size_type n) noexcept {
                return value_[n];
            }

            const_reference
            operator[](size_type n) const noexcept {
                return value_[n];
            }

            reference
            at(size_type n) {
                return value_.at(n);
            }

            const_reference
            at(size_type n) const {
                return value_.at(n);
            }

            size_type
            size() const noexcept { return N; }

            iterator
            begin() noexcept {
                return value_.begin();
            }

            iterator
            end() noexcept {
                return value_.end();
            }

            friend Vector<T, N>
            operator+(const Vector<T, N>& lhs, const Vector<T, N>& rhs) {
                Vector<T, N> result = {};
                for (size_type i = 0; i < N; i++) { result[i] = lhs[i] + rhs[i]; }
                return result;
            }

            friend Vector<T, N>
            operator-(const Vector<T, N>& lhs, const Vector<T, N>& rhs) {
                Vector<T, N> result = {};
                for (size_type i = 0; i < N; i++) { result[i] = lhs[i] - rhs[i]; }
                return result;
            }

            friend bool
            operator==(const Vector<T, N>& lhs, const Vector<T, N>& rhs) {
                const T TOLERANCE = 1e-3;
                for (size_type i = 0; i < N; i++) {
                    if ((lhs[i] == rhs[i]) or (std::abs(lhs[i] - rhs[i]) <= TOLERANCE)) { 
                        continue; 
                    } else {
                        return false;
                    }
                }
                return true;
            }

            friend bool
            operator!=(const Vector<T, N>& lhs, const Vector<T, N>& rhs) {
                return (not (lhs == rhs));
            }
        private:
            std::array<T, N> value_;
    };
} // namespace conjugate

#endif //  CONJUGATE_HPP__
