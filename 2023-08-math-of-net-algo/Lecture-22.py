import numpy as np
import pandas as pd

train_df = pd.read_csv("train.csv")

#train_df.info()
#train_df.columns.values
#['PassengerId', 'Survived', 'Pclass', 'Name', 'Sex', 'Age', 'SibSp',
#'Parch', 'Ticket', 'Fare', 'Cabin', 'Embarked'],

#train_df['Survived'].describe()
#train_df['Pclass'].describe()

# The training-set has 891 examples and 11 features + the target variable (survived).
#survival:    Survival 
#PassengerId: Unique Id of a passenger. 
#pclass:    Ticket class     
#sex:    Sex     
#Age:    Age in years     
#sibsp:    # of siblings / spouses aboard the Titanic     
#parch:    # of parents / children aboard the Titanic     
#ticket:    Ticket number     
#fare:    Passenger fare     
#cabin:    Cabin number     
#embarked:    Port of Embarkation



train_df = train_df.drop(['PassengerId'], axis=1)
train_df = train_df.drop(['Name'], axis=1)
train_df = train_df.drop(['Ticket'], axis=1)

#train_df['Cabin'].describe() Very low count
train_df = train_df.drop(['Cabin'], axis=1)

#train_df['Age'].describe() Very low count

print("Before Process: Missing age values", train_df["Age"].isnull().sum())

def add_missing_values_age(data):
    mean = data["Age"].mean()
    std = data["Age"].std()
    is_null = data["Age"].isnull().sum()
    # compute random numbers between the mean, std and is_null
    rand_age = np.random.randint(mean - std, mean + std, size = is_null)
    # fill NaN values in Age column with random values generated
    age_slice = data["Age"].copy()
    age_slice[np.isnan(age_slice)] = rand_age
    data["Age"] = age_slice
    data["Age"] = train_df["Age"].astype(int)
    return data

train_df = add_missing_values_age(train_df)
print("After Process: Missing age values", train_df["Age"].isnull().sum())


#train_df['Embarked'].describe()

print("Before Process: Missing Embarked values", train_df["Embarked"].isnull().sum())
def add_missing_values_embarked(data):
    common_value = data['Embarked'].describe()['top']
    data['Embarked'] = data['Embarked'].fillna(common_value)
    return data

train_df = add_missing_values_embarked(train_df)
print("After Process: Missing Embarked values", train_df["Embarked"].isnull().sum())
 
    
#Converting Features:

#Convert ‘Sex’ feature into numeric.
genders = {"male": 0, "female": 1}
train_df['Sex'] = train_df['Sex'].map(genders)

#Convert Embarked into number
ports = {"S": 0, "C": 1, "Q": 2}
train_df['Embarked'] = train_df['Embarked'].map(ports)


x_train_df = train_df.drop("Survived", axis=1)
y_train_df = train_df['Survived'].values

x_train = x_train_df.to_numpy()
y_train = y_train_df # Already a numpy arra

from keras import models
from keras import layers

model = models.Sequential()
model.add(layers.Dense(10, activation='relu', input_shape=(7,)))
#model.add(layers.Dense(10, activation='relu'))
model.add(layers.Dense(1, activation='sigmoid'))

x_val = x_train[:100] # First 100 entries
partial_x_train = x_train[100:] # Remaining entries
y_val = y_train[:100]
partial_y_train = y_train[100:]

model.compile(optimizer='rmsprop', loss='binary_crossentropy', metrics=['acc'])
#model.compile(optimizer='rmsprop', loss='mse', metrics=['acc'])
history = model.fit(partial_x_train, partial_y_train, epochs=40, batch_size=32, validation_data=(x_val, y_val),verbose=2)

#X_test  = test_df.drop("PassengerId", axis=1).copy()