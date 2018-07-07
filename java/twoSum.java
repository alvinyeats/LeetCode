/******
初阶：遍历nums, 依次查找target-nums[n]是否存在于nums中
高阶：对nums进行去重整理，生成<key,[key, key, ...]>形式，再遍历查找

 */


class Solution{
  public int[] twoSum(int[] nums, int target) {
    int[] rst = new int[2];
    for(int x=0; x < nums.length; x++){
        int j = 1;
        while((x+j) < nums.length){
            if((nums[x]+nums[x+j])==target){
                rst[0] = x;
                rst[1] = x+j;
                return rst;
            }
            j++;
        }
    }
    return rst;
  }
}