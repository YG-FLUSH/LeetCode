#!/usr/bin/env python
# -*- coding: utf-8 -*-
#   Author: Yoge
#   Time: 2018/06/28


class Solution(object):
    def mincostToHireWorkers(self, quality, wage, K):
        """
        :type quality: List[int]
        :type wage: List[int]
        :type K: int
        :rtype: float
        """
        # quality/wage获取性价比
        # 按性价比从低到高排序,判断高性价比的员工是否能够满足K个。
        # 如果高性价比的员工单价特别高呢?

        # 按低单价 高性价比重新排一次序
        # 选择前K个低单价的, 满足高性价比的员工。
        # 最后再来凑数

        cost_effective = [q/float(w) for q, w in zip(quality, wage)]
        cost_effective_map = {v:i for i, v in enumerate(cost_effective)}
        cost_effective_order = sorted(cost_effective_map, reverse=True)
        wage_map = {v: i for i, v in enumerate(wage)}
        wage_order = sorted(wage_map)
