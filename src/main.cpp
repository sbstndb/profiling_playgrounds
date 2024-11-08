#include <iostream>
#include <vector>
// are we sure there will not be auto inlining ? 
template <typename V>
[[gnu::noinline]]
void compute_vector(V& a, V& b , V& c, std::size_t size){
	for (std::size_t i = 0 ; i < size ; i++){
		// std vector
		c[i] = a[i] + b[i] ; 
	}
//        for (int i = 0 ; i < size ; i++){
//                a[i] = b[i] + c[i] ;
//        }
//        for (int i = 0 ; i < size ; i++){
//                b[i] = c[i] + a[i] ;
//        }	
}

[[gnu::noinline]]
void compute_raw(float* a, float* b , float* c, std::size_t size){
        for (unsigned int i = 0 ; i < size ; i++){
		// raw pointer
                c[i] = a[i] + b[i] ;
        }
}


void Hello(int test){
	std::cout << " Hello, world " << test <<  std::endl ; 
}


int main(){

	Hello(1) ; 

	std::size_t size = 102400000 ; 
	int loop = 1 ; 

	std::vector<float> a(size, 0.00000001) ;
	std::vector<float> b(size, -0.00000001) ; 
	std::vector<float> c(size, -0.00000001) ; 

	float *d_a, *d_b, *d_c;
	d_a = (float*)malloc(size * sizeof(float)); 
        d_b = (float*)malloc(size * sizeof(float));
        d_c = (float*)malloc(size * sizeof(float));
	


	// compute
	compute_vector(a, b, c, size) ; 

	compute_raw(d_a, d_b, d_c, size);

	// avoid code deletion
	std::cout << " Last value is : " << c.back() << std::endl ;


	free(d_a) ;
	free(d_b) ; 
	free(d_c) ; 

	return 0 ; 
}
