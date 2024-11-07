#include <iostream>
#include <vector>
// are we sure there will not be auto inlining ? 
template <typename V>
void compute(V& a, V& b , V& c, std::size_t size){
	for (int i = 0 ; i < size ; i++){
		c[i] = a[i] + b[i] ; 
	}
//        for (int i = 0 ; i < size ; i++){
//                a[i] = b[i] + c[i] ;
//        }
//        for (int i = 0 ; i < size ; i++){
//                b[i] = c[i] + a[i] ;
//        }	

}


int main(){
	std::cout << "Hello, world " <<std::endl ; 


	std::size_t size = 1024000 ; 
	int loop = 1 ; 

	std::vector<float> a(size, 0.00000001) ;
	std::vector<float> b(size, -0.00000001) ; 
	std::vector<float> c(size, -0.00000001) ; 

	// compute
	for (int i = 0 ; i < loop ; i++){
		compute(a, b, c, size) ; 
	}

	// avpid code deletion
	std::cout << " Last value is : " << c.back() << std::endl ;

	return 0 ; 
}
