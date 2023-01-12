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
		track(const unsigned int alloc){
			num=alloc;
			array = new T[size];
		}
		// Forget
		~track(){
			if(num)delete [] array;
		}
		// Reset num
		unsigned int resize(const unsigned int new_num){
			if(num==new_num)return num;
			if(new_num){
				T *new_track = new T[new_num];
				unsigned int total=num<new_num?num:new_num;
				for(int i=0;i<total;i++){
					new_track[i]=array[i];
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
		T access(const unsigned int offset){
			if(offset<num&&num){
				return array[offset];
			}
			// WARNING:NO RETURN
		}
		T access(const unsigned int offset,T obj){
			if(offset<num&&num){
				array[offset]=obj;
				return array[offset];
			}
			// WARNING:NO RETURN
		}
		// access
		T & operator[] (const unsigned int offset){
			if(offset<num&&num){
				return array[offset];
			}
			// WARNING:NO RETURN
		}
		// (I don't know how to name it...)
		track &operator=(track &t){
			if(this->num)delete [] this->array;
			this->num=t.num;
			if(t.num)this->array=new T[this->num];
			for(int i=0;i<t.num;i++){
				this->array[i]=t.array[i];
			}
			return *this;
		}
		// Insert
		unsigned int insert(const unsigned int offset,const T object){
			resize(num+1);
			for(int i=num-1;i>offset+1;i--){
				array[i]=array[i-1];
			}
			array[offset]=object;
			return offset;
		}
		
		
		/* This function has some bugs. */
		
		// Insert(Copy)
		//unsigned int insert(track &t,const unsigned int from_offset,const unsigned int to_offset,const unsigned int large){
//			if(t.num>from_offset+large){
//				resize(num+large);
//				// NOTICE:It won't check the t.array . 
//				for(int i=num-1;i>to_offset+large;i--){
//					array[i]=array[i-1];
//				}
//				for(int i=0;i<large;i++){
//					array[to_offset+i]=t.array[from_offset+i];
//				}
//				return large;
//			}
//			return 0;
//		}
		
		
		// Cover(Copy) (Limit size)
		unsigned int cover(track &t,const unsigned int from_offset,const unsigned int to_offset,const unsigned int large){
			if(t.num>from_offset+large){
				//                   vvvvv  (Limit)
				for(int i=0;i<large&&i<num;i++){
					array[i+to_offset]=t.array[i+from_offset];
				}
				return large;
			}
			return 0;
		}
};

}

#endif
