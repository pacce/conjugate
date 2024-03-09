#ifndef CONJUGATE_HPP__
#define CONJUGATE_HPP__

#include <array>
#include <cmath>
#include <cstdint>
#include <ostream>
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
            Vector() {
                for (size_type i = 0; i < N; i++) { value_[i] = 0.0; }
            }
            Vector(const std::array<T, N>& xs) : value_(xs) {}
            Vector(T x) {
                for (size_type i = 0; i < N; i++) { value_[i] = x; }
            }

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

            friend Vector<T, N>
            operator*(const Vector<T, N>& v, T scalar) {
                Vector<T, N> result = v;
                for (size_type i = 0; i < N; i++) { result[i] *= scalar; }
                return result;
            }

            friend Vector<T, N>
            operator*(T scalar, const Vector<T, N>& v) {
                Vector<T, N> result = v;
                for (size_type i = 0; i < N; i++) { result[i] *= scalar; }
                return result;
            }

            value_type
            dot(const Vector<T, N>& other) const {
                value_type sum = 0.0;
                for (size_type i = 0; i < N; i++) {
                    sum += (value_[i] * other[i]);
                }
                return sum;
            }

            friend std::ostream&
            operator<<(std::ostream& os, const Vector<T, N>& v) {
                os << "[";
                for (size_type i = 0; i < N; i++) {
                    os << v[i] << ((i == (N - 1)) ? "]" : ",");
                }
                os << std::endl;
                return os;
            }
        private:
            std::array<T, N> value_;
    };

    template <typename T, std::size_t N, std::size_t M>
    class Matrix {
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
            Matrix() {
                for (size_type i = 0; i < N * M; i++) { value_[i] = 0.0; }
            }
            Matrix(const std::array<T, N * M>& xs) : value_(xs) {}
            Matrix(T x) {
                for (size_type i = 0; i < N * M; i++) { value_[i] = x; }
            }

            reference
            operator[](size_type n) noexcept {
                return value_[n];
            }

            const_reference
            operator[](size_type n) const noexcept {
                return value_[n];
            }

            reference
            operator[](std::pair<size_type, size_type> p) noexcept {
                return value_[p.first + N * p.second];
            }

            const_reference
            operator[](std::pair<size_type, size_type> p) const noexcept {
                return value_[p.first + N * p.second];
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
            size() const noexcept { return N * M; }

            iterator
            begin() noexcept {
                return value_.begin();
            }

            iterator
            end() noexcept {
                return value_.end();
            }

            friend bool
            operator==(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs) {
                const T TOLERANCE = 1e-3;
                for (size_type i = 0; i < N * M; i++) {
                    if ((lhs[i] == rhs[i]) or (std::abs(lhs[i] - rhs[i]) <= TOLERANCE)) {
                        continue;
                    } else {
                        return false;
                    }
                }
                return true;
            }

            friend bool
            operator!=(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs) {
                return (not (lhs == rhs));
            }

            friend Matrix<T, N, M>
            operator+(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs) {
                Matrix<T, N, M> result = {};
                for (size_type i = 0; i < N * M; i++) { result[i] = lhs[i] + rhs[i]; }
                return result;
            }

            friend Matrix<T, N, M>
            operator-(const Matrix<T, N, M>& lhs, const Matrix<T, N, M>& rhs) {
                Matrix<T, N, M> result = {};
                for (size_type i = 0; i < N * M; i++) { result[i] = lhs[i] - rhs[i]; }
                return result;
            }

            friend Vector<T, M>
            operator*(const Matrix<T, N, M>& lhs, const Vector<T, N>& rhs) {
                Vector<T, M> result(0.0f);
                for (size_t j = 0; j < M; j++) {
                for (size_t i = 0; i < N; i++) {
                    result[j] += lhs[std::make_pair(i, j)] * rhs[i];
                }
                }
                return result;
            }

            friend Vector<T, N>
            operator*(const Vector<T, M>& lhs, const Matrix<T, N, M>& rhs) {
                Vector<T, N> result(0.0f);
                for (size_t j = 0; j < M; j++) {
                for (size_t i = 0; i < N; i++) {
                    result[i] += (lhs[j] * rhs[std::make_pair(i, j)]);
                }
                }
                return result;
            }

            friend std::ostream&
            operator<<(std::ostream& os, const Matrix<T, N, M>& v) {
                os << N * M << std::endl;
                os << std::endl;
                for (size_type j = 0; j < M; j++) {
                    os << "[";
                    for (size_type i = 0; i < N; i++) {
                        std::pair<size_type, size_type> p{i, j};
                        os  << v[p]
                            << ((i == (N - 1)) ? "" : ",")
                            ;
                    }
                    os << "]" << std::endl;
                }
                return os;
            }
        private:
            std::array<T, N * M> value_;
    };
} // namespace conjugate

#endif //  CONJUGATE_HPP__
