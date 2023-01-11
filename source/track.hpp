#ifndef WAVETRACK_H_HANAKO
#define WAVETRACK_H_HANAKO

/* ARRAY */

namespace Hanako{

template<class T>
class track{
	protected:
		// Size;
		unsigned int num;
		// Array
		T *array;
	public:
		// Reset
		unsigned int reset(void){
			if(num)delete [] array;
			num=0;
			return 0;
		}
		// Create
		track(void){// Empty
			num=0;
			array = (T*)0;
		}
		// Forget
		~track(){
			if(num)delete [] array;
		}
		// Reset num
		unsigned int resize(unsigned int new_num){
			if(num==new_num)return num;
			if(new_num){
				T *new_track = new T[new_num];
				T *p=new_track;
				T *q=array;
				unsigned int total=num<new_num?num:new_num;
				for(int i=0;i<total;i++){
					*p=*q;
					p++;
					q++;
				}
				if(num)delete [] array;
				array=new_track;
				num=new_num;
			}else reset();
			return num;
		}
		// Size
		unsigned int size(void){
			return num;
		}
		// access
		T access(unsigned int offset){
			if(offset<num&&num){
				return array[offset];
			}
		}
		T access(unsigned int offset,T obj){
			if(offset<num&&num){
				array[offset]=obj;
				return array[offset];
			}
		}
		
};

}

#endif
