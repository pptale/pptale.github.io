import numpy as np
from scipy.optimize import linprog, milp, LinearConstraint, Bounds


# ===========================================================
# PART 1: LINEAR PROGRAMMING (LP) USING linprog
# ===========================================================

def solve_basic_lp():
    """
    Minimize:
        3x + 2y

    Subject to:
        x + y <= 4
        x <= 2
        y <= 3
        x, y >= 0
    """

    print("\n--- Basic Linear Program (LP) ---")

    c = [3, 2]

    A_ub = [
        [1, 1],
        [1, 0],
        [0, 1]
    ]
    b_ub = [4, 2, 3]

    bounds = [(0, None), (0, None)]

    res = linprog(
        c,
        A_ub=A_ub,
        b_ub=b_ub,
        bounds=bounds,
        method="highs"
    )

    print("Optimal solution:", res.x)
    print("Optimal value:", res.fun)
    print("Success:", res.success)


def solve_lp_with_equality():
    """
    Minimize:
        x + y

    Subject to:
        x + 2y = 4
        x, y >= 0
    """

    print("\n--- LP with Equality Constraint ---")

    c = [1, 1]
    A_eq = [[1, 2]]
    b_eq = [4]
    bounds = [(0, None), (0, None)]

    res = linprog(
        c,
        A_eq=A_eq,
        b_eq=b_eq,
        bounds=bounds,
        method="highs"
    )

    print("Optimal solution:", res.x)
    print("Optimal value:", res.fun)


def solve_maximization_lp():
    """
    Maximize:
        5x + 4y

    Subject to:
        6x + 4y <= 24
        x + 2y <= 6
        x, y >= 0
    """

    print("\n--- LP Maximization (via minimization) ---")

    c = [-5, -4]  # negate objective for maximization

    A_ub = [
        [6, 4],
        [1, 2]
    ]
    b_ub = [24, 6]

    bounds = [(0, None), (0, None)]

    res = linprog(
        c,
        A_ub=A_ub,
        b_ub=b_ub,
        bounds=bounds,
        method="highs"
    )

    print("Optimal solution:", res.x)
    print("Maximum value:", -res.fun)


# ===========================================================
# PART 2: INTEGER LINEAR PROGRAMMING (ILP / MILP)
# Using scipy.optimize.milp
# ===========================================================

def solve_integer_lp():
    """
    Integer Linear Program

    Minimize:
        x + y

    Subject to:
        2x + y >= 4
        x + 2y >= 4
        x, y are integers >= 0
    """

    print("\n--- Integer Linear Program (ILP) ---")

    c = np.array([1, 1])

    A = np.array([
        [2, 1],
        [1, 2]
    ])
    lb = np.array([4, 4])
    ub = np.array([np.inf, np.inf])

    constraints = LinearConstraint(A, lb, ub)

    bounds = Bounds([0, 0], [np.inf, np.inf])

    integrality = np.array([1, 1])  # 1 = integer, 0 = continuous

    res = milp(
        c=c,
        constraints=constraints,
        bounds=bounds,
        integrality=integrality
    )

    print("Optimal integer solution:", res.x)
    print("Optimal value:", res.fun)


def solve_binary_lp():
    """
    Binary Integer Program

    Maximize:
        3x + 2y + z

    Subject to:
        x + y + z <= 2
        x, y, z in {0,1}
    """

    print("\n--- Binary Integer Linear Program ---")

    c = -np.array([3, 2, 1])  # negate for maximization

    A = np.array([[1, 1, 1]])
    lb = np.array([-np.inf])
    ub = np.array([2])

    constraints = LinearConstraint(A, lb, ub)

    bounds = Bounds([0, 0, 0], [1, 1, 1])
    integrality = np.array([1, 1, 1])

    res = milp(
        c=c,
        constraints=constraints,
        bounds=bounds,
        integrality=integrality
    )

    print("Optimal binary solution:", res.x)
    print("Maximum value:", -res.fun)


# ===========================================================
# MAIN DRIVER
# ===========================================================

if __name__ == "__main__":

    solve_basic_lp()
    solve_lp_with_equality()
    solve_maximization_lp()

    solve_integer_lp()
    solve_binary_lp()

    print("\nAll LP and ILP demos completed successfully.")
