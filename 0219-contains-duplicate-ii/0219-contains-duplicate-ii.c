typedef struct {
    int val;
    int index;
} Element;

int compareElements(const void* a, const void* b) {
    Element* elemA = (Element*)a;
    Element* elemB = (Element*)b;
    
    if (elemA->val != elemB->val) {
        return (elemA->val > elemB->val) - (elemA->val < elemB->val);
    }
    return elemA->index - elemB->index;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (numsSize <= 1 || k <= 0) {
        return false;
    }

    Element* elements = (Element*)malloc(numsSize * sizeof(Element));
    if (!elements) return false;

    for (int i = 0; i < numsSize; i++) {
        elements[i].val = nums[i];
        elements[i].index = i;
    }

    qsort(elements, numsSize, sizeof(Element), compareElements);

    for (int i = 0; i < numsSize - 1; i++) {
        if (elements[i].val == elements[i + 1].val) {
            if (abs(elements[i].index - elements[i + 1].index) <= k) {
                free(elements);
                return true;
            }
        }
    }

    free(elements);
    return false;
}