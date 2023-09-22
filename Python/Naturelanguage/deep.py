import numpy as np
import tensorflow as tf
from tensorflow.keras.datasets import imdb
from tensorflow.keras.preprocessing.sequence import pad_sequences
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Flatten, Embedding, Dropout

# 设置超参数
vocab_size = 10000
max_length = 256
embedding_dim = 16
num_epochs = 10
batch_size = 128

# 加载数据集
(x_train, y_train), (x_test, y_test) = imdb.load_data(num_words=vocab_size)

# 数据预处理
x_train = pad_sequences(x_train, maxlen=max_length, padding='post', truncating='post')
x_test = pad_sequences(x_test, maxlen=max_length, padding='post', truncating='post')

# 构建模型
model = Sequential([
    Embedding(input_dim=vocab_size, output_dim=embedding_dim, input_length=max_length),
    Flatten(),
    Dense(64, activation='relu'),
    Dropout(0.5),
    Dense(1, activation='sigmoid')
])
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# 训练模型
model.fit(x_train, y_train, epochs=num_epochs, batch_size=batch_size, validation_data=(x_test, y_test))

# 测试模型
test_text = "This movie is great!"
test_text_sequence = np.array([np.array([word_index[word] if word in word_index else 0 for word in test_text.split()])])
test_text_sequence = pad_sequences(test_text_sequence, maxlen=max_length, padding='post', truncating='post')
prediction = model.predict(test_text_sequence)[0][0]
if prediction >= 0.5:
    print("Positive sentiment")
else:
    print("Negative sentiment")