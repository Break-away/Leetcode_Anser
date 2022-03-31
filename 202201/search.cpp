/*��֪����һ�����ǽ������е��������� nums �������е�ֵ���ػ�����ͬ��
�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ��ת ��ʹ�����Ϊ
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]���±� �� 0 ��ʼ ��������
���磬 [0,1,2,4,4,4,5,6,6,7] ���±� 5 ������ת����ܱ�Ϊ [4,5,6,6,7,0,1,2,4,4] ��
���� ��ת�� ������ nums ��һ������ target �������дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С�
��� nums �д������Ŀ��ֵ target ���򷵻� true �����򷵻� false ��*/

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return false;
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            /*�������ʱ*/
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            else if (nums[left] <= nums[mid]) {
                /*targetλ�����*/
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }
                else left = mid + 1;
            }
            /*�Ҳ�����ʱ*/
            else {
                /*targetλ���Ҳ�*/
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                }
                else right = mid - 1;
            }
        }
        return false;
    }
};